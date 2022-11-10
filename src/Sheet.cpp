#pragma once
#include "Sheet.h"
#include "BPlusTree.h"

Sheet::Sheet(){
            std::string dirPath = SheetDataDir;
            if(access(dirPath.c_str(),F_OK) == -1){ // need create a new one
                        int isCreateDir = mkdir(dirPath.c_str(), S_IRUSR | S_IWUSR | S_IXUSR | S_IRWXG | S_IRWXO);
                        if(isCreateDir == -1){
                                    std::cout<<"Error: fail to store the BPlusTree since DirCreation failed!"<<std::endl;
                                    std::cout<<"errno: "<< errno<<": "<<strerror(errno)<<std::endl;
                        }
            }
            std::string filePath = SheetDataPath;
            mFp = open(filePath.c_str(), O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
            if(mFp == -1){
                        std::cout<<"Error: Fail to Open the file"<<std::endl;
            }
            mBplusTree = new BPlusTree();
            struct stat file_stat;
            int ret = fstat(mFp, &file_stat);
            if(ret == -1){
                        std::cout<<"Error: fail to get the size of the sheetFile!"<<std::endl;
		close(mFp);
            }
            if(file_stat.st_size == 0){ // Empty file: requres set sheet
                        lineNum = 0;
                        if(SetRawSheet()){
                                   // mBplusTree->BuildBPlussTree(piecesArray, lineNum);       
                        }
                        else{
                                    std::cout<<"Error: Fail to set the raw sheet!"<<std::endl;
                                    close(mFp);
                        } 
                       
            }
            else{  // the sheet file exits: access the data
                        lineNum = file_stat.st_size/PieceSize;
                        if(lseek(mFp, 0, SEEK_SET) == -1){
                                    std::cout<<"Error: Fail to lseek!"<<std::endl;
                                    close(mFp);
                        }
                        if(read(mFp,piecesArray,file_stat.st_size) == -1){
                                    std::cout<<"Error: Fail to read the sheetFile!"<<std::endl;
                                    close(mFp);
                        }
                        if(!mBplusTree->InitializeBPlussTree()){
                                     std::cout<<"Error: Fail to read a new sheet!"<<std::endl;
                                     close(mFp);
                        }
            }
            srand((unsigned)time(0));  // this is for rand   
            mmutexFIndInsertSheet = new pthread_mutex_t;
            if(pthread_mutex_init(mmutexFIndInsertSheet, 0)!=0){
                        std::cout<<"Error: Fail to init mutexFIndInsertSheet!"<<std::endl;
                        delete mmutexFIndInsertSheet;
                        close(mFp);
            }
}

pthread_mutex_t *Sheet::GetNewMutex(){
            pthread_mutex_t *tempMutex = new pthread_mutex_t;
            if (pthread_mutex_init(tempMutex, 0) != 0) {
                        delete tempMutex;
                        std::cout<<"Error: Fail to Initialize the Mutex"<<std::endl;
                        return nullptr;
            }
    return tempMutex;
}

pthread_mutex_t* Sheet::mmutexGetSheet = Sheet::GetNewMutex();

Sheet *Sheet::mSheet = nullptr;

bool Sheet::SetRawSheet(){
            Piece piece;
            for(int i=0;i<rawLineNUm;i++){
                        piece = GetNewPiece();
                        if(!AppendSheet(piece)){
                                     std::cout<<"Error: Fail to Set the Raw sheet!"<<std::endl;
                                     return false;
                        }
            }
            return true;
}

bool Sheet::AppendSheet(Piece piece){
            if(write(mFp, &piece,PieceSize) == -1){
                         std::cout<<"Error: fail to append a new piece!"<<std::endl;
                         return false;
            }
            if(!mBplusTree->UpdateBPlusTree(piece)){
                        std::cout<<"Error: fail to append a new piece!"<<std::endl;
                        return false;
            }
            return true;
}

Piece Sheet::GetNewPiece(){
            Piece piece;
            piece.lineNum = lineNum;
            for(int i=0;i<MaxAttributeNumber;i++){
                        int64_t temp = rand();
                        if(temp%2){  // Limit the numers within -999 to 999
                                  piece.arrtibute[i] = temp%1000;
                        }
                        else{
                                    piece.arrtibute[i] = 0-temp%1000;
                        }
                        
            }
            piecesArray[lineNum] = piece;
            lineNum++;
            return piece;
}



Sheet::~Sheet(){
           // std::cout<<"Start ~Sheet"<<std::endl;
            if(mFp){
                 close(mFp);       
            }
            if(mBplusTree!=nullptr){
                        delete(mBplusTree);
            }
}

Sheet *Sheet:: GetSheet(){
            if (pthread_mutex_lock(mmutexGetSheet) != 0) {
                        std::cout<<"Error: Fail to lock mmutexGetSheet"<<std::endl;
                        return nullptr;
            }
            if(mSheet != nullptr){
                        std::cout<<"msheet already exist"<<std::endl;
                        if (pthread_mutex_unlock(mmutexGetSheet) != 0) {
                                    std::cout<<"Error: Fail to unlock mmutexGetSheet"<<std::endl;
                                    return nullptr;
                         }           
                        return mSheet; // to assure there is only one instance
            }
            mSheet = new Sheet();
            if(mSheet == nullptr){
                        std::cout<<"Error: Fail to New a Sheet"<<std::endl;
            }
            if (pthread_mutex_unlock(mmutexGetSheet) != 0) {
                        std::cout<<"Error: Fail to unlock mmutexGetSheet"<<std::endl;
                        return nullptr;
            }
            return mSheet;
}


void Sheet::DisplayPiece(Piece piece){
            std::cout<<"LINENUM:"<<piece.lineNum<<std::endl;
            std::cout<<"ATTRIBUTES:"<<std::endl;
             for(int i=0;i<MaxAttributeNumber;i++){
                        std::cout<<piece.arrtibute[i]<<" ";
             }
            std::cout<<std::endl;
}


bool Sheet::InsertPiece(){
            if (pthread_mutex_lock(mmutexFIndInsertSheet) != 0){
		std::cout<<"Error: Fail to lock mmutexFIndInsertSheet"<<std::endl;
                        return false;
	}
            Piece newPiece = GetNewPiece();
            if(!AppendSheet(newPiece)){
                         std::cout<<"Error: fail to insert piece"<<std::endl;
                        if (pthread_mutex_unlock(mmutexFIndInsertSheet) != 0){
                                    std::cout<<"Error: Fail to unlock mmutexFIndInsertSheet"<<std::endl;
	            }
                         return false;
            }
            std::cout<<"******************************************"<<std::endl;
            std::cout<<"HERE IS THE NEW PIECE:"<<std::endl;
            DisplayPiece(newPiece);
            std::cout<<"******************************************"<<std::endl;
             if (pthread_mutex_unlock(mmutexFIndInsertSheet) != 0){
		std::cout<<"Error: Fail to unlock mmutexFIndInsertSheet"<<std::endl;
                        return false;
	}
            return true;
}

void Sheet::FindPieces(int64_t targetVal,int colNum){
            if (pthread_mutex_lock(mmutexFIndInsertSheet) != 0){
		std::cout<<"Error: Fail to lock mmutexFIndInsertSheet"<<std::endl;
                        return;
	}
            std::vector<int64_t> ans;
            mBplusTree->findSingleValue(targetVal,colNum,ans);
            if(ans.size()==0){
                         std::cout<<"There is no data fitting the requirement!"<<std::endl;
             }
            else{
                        std::cout<<"******************************************"<<std::endl;
                        std::cout<<"HERE ARE THE FINDINGS:"<<std::endl;
                        for(int i=0;i<ans.size();i++){
                                    std::cout<<ans[i]<<std::endl;
                                    DisplayPiece(piecesArray[ans[i]]);
                                    std::cout<<"******************************************"<<std::endl;
                         }
            }
             if (pthread_mutex_unlock(mmutexFIndInsertSheet) != 0){
		std::cout<<"Error: Fail to unlock mmutexFIndInsertSheet"<<std::endl;
                        return;
	}
}

void Sheet::FindPieces(int64_t minVal, int64_t maxVal, int colNum){
             if (pthread_mutex_lock(mmutexFIndInsertSheet) != 0){
		std::cout<<"Error: Fail to lock mmutexFIndInsertSheet"<<std::endl;
                        return;
	}
             std::vector<int64_t> ans;
            mBplusTree->findScopeValue(minVal,maxVal,colNum,ans);
            if(ans.size()==0){
                         std::cout<<"There is no data fitting the requirement!"<<std::endl;
             }
             else{
                        std::cout<<"******************************************"<<std::endl;
                        std::cout<<"HERE ARE THE FINDINGS:"<<std::endl;
                        for(int i=0;i<ans.size();i++){
                                    DisplayPiece(piecesArray[ans[i]]);
                        }
                        std::cout<<"******************************************"<<std::endl;
            }
            if (pthread_mutex_unlock(mmutexFIndInsertSheet) != 0){
		std::cout<<"Error: Fail to unlock mmutexFIndInsertSheet"<<std::endl;
                        return;
	}
}