#include "sheet.h"
#include "BPlusTree.h"

Sheet::Sheet(){
            mFp = open(SheetFilePath, O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
            if(mFp == -1){
                        std::cout<<"Fail to Open the file"<<std::endl;
            }
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
            srand((unsigned)time(0));  // this is for rand
            mBplusTree = new BPlusTree();
            
}
 

bool Sheet::SetRawSheet(){
            Piece piece;
            for(int i=0;i<rawLineNUm;i++){
                        piece = GetNewSheet();
                        if(AppendSheet(piece)){
                                     std::cout<<"Error: Fail to Set the Raw sheet!"<<std::endl;
                                     return false;
                        }
            }

}

bool Sheet::AppendSheet(Piece piece){
            if(write(mFp, &piece,PieceSize) == -1){
                         std::cout<<"Error: fail to Append a New Piece!"<<std::endl;
                         return false;
            }
            return true;
}

Piece Sheet::GetNewSheet(){
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