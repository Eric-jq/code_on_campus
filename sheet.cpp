#include "sheet.h"
#include "BPlusTree.h"

Sheet::Sheet(){
            mFp = open(SheetFilePath, O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
            if(mFp == -1){
                        std::cout<<"Fail to Open the file"<<std::endl;
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
                        if(!SetRawSheet()){
                                     //std::cout<<"Error: Fail to get the size of the sheetFile!"<<std::endl;
                                    mBplusTree->BuildBPlussTree(piecesArray, lineNum);
                                    close(mFp);
                        }
            }
            else{  // the sheet file exits: access the data
                        lineNum = file_stat.st_size/PieceSize;
                        if(lseek(mFp, 0, SEEK_SET) == -1){
                                    std::cout<<"Error: Fail to lseek!"<<std::endl;
                        }
                        if(read(mFp,piecesArray,file_stat.st_size) == -1){
                                    std::cout<<"Error: Fail to read the sheetFile!"<<std::endl;
                        }
            }
            mBplusTree->InitializeBPlussTree();
            srand((unsigned)time(0));  // this is for rand
            
            
}
 

bool Sheet::SetRawSheet(){
            Piece piece;
            for(int i=0;i<rawLineNUm;i++){
                        piece = GetNewPiece();
                        if(AppendSheet(piece)){
                                     std::cout<<"Error: Fail to Set the Raw sheet!"<<std::endl;
                                     return false;
                        }
            }
}

bool Sheet::AppendSheet(Piece piece){
            if(write(mFp, &piece,PieceSize) == -1){
                         std::cout<<"Error: fail to append a new piece!"<<std::endl;
                         return false;
            }
            mBplusTree->UpdateBPlusTree(piece);
            return true;
}

Piece Sheet::GetNewPiece(){
            Piece piece;
            piece.lineNum = lineNum;
            for(int i=0;i<MaxAttributeNumber;i++){
                        int64_t temp = rand();
                        if(temp%2){
                                  piece.arrtibute[i] = temp;
                        }
                         piece.arrtibute[i] = 0-temp;
            }
            piecesArray[lineNum] = piece;
            return piece;
}

Sheet *Sheet:: getSheet(){
            if(mSheet != nullptr){
                        return mSheet; // to assure there is only one instance
            }
            mSheet = new Sheet();
            return mSheet;
}


void Sheet::DisplayPiece(Piece piece){
            std::cout<<"LINENUM:"<<lineNum<<std::endl;
            std::cout<<"ATTRIBUTES:"<<lineNum<<std::endl;
             for(int i=0;i<MaxAttributeNumber;i++){
                        std::cout<<piece.arrtibute[i]<<" ";
             }
}


bool Sheet::InsertPiece(){
            Piece newPiece = GetNewPiece();
            if(!AppendSheet(newPiece)){
                         std::cout<<"Error: fail to insert piece"<<std::endl;
                         return false;
            }
            std::cout<<"******************************************"<<std::endl;
            std::cout<<"HERE IS THE NEW PIECE:"<<std::endl;
            DisplayPiece(newPiece);
            std::cout<<"******************************************"<<std::endl;
            return true;
}

void Sheet::FindPieces(int64_t targetVal,int colNum){
            std::vector<int64_t> ans;
            mBplusTree->findSingleValue(targetVal,colNum,ans);
            std::cout<<"******************************************"<<std::endl;
             std::cout<<"HERE ARE THE FINDINGS:"<<std::endl;
            for(int i=0;i<ans.size();i++){
                        DisplayPiece(piecesArray[ans[i]]);
            }
            std::cout<<"******************************************"<<std::endl;
}

void Sheet::FindPieces(int64_t minVal, int64_t maxVal, int colNum){
             std::vector<int64_t> ans;
            mBplusTree->findScopeValue(minVal,maxVal,colNum,ans);
            std::cout<<"******************************************"<<std::endl;
             std::cout<<"HERE ARE THE FINDINGS:"<<std::endl;
            for(int i=0;i<ans.size();i++){
                        DisplayPiece(piecesArray[ans[i]]);
            }
            std::cout<<"******************************************"<<std::endl;

}