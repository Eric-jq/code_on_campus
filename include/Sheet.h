#pragma once

#include "piece.h"
#include "BPlusTree.h"
#include <time.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#define rawLineNUm 10
#define maxLineNum 1000000
#define SheetDataDir "../SheetDataDir"
#define SheetDataPath "../SheetDataDir/SheetData"

class Sheet{
            public:
                        Sheet();
                        ~Sheet();
                       static Sheet * GetSheet();
                        bool InsertPiece();
                        void FindPieces(int64_t targetVal,int colNum);
                        void FindPieces(int64_t minVal, int64_t maxVal, int colNum);
                        static pthread_mutex_t * GetNewMutex();
            
            private:
                         BPlusTree *mBplusTree;
                        bool SetRawSheet();
                        Piece GetNewPiece(); 
                        bool AppendSheet(Piece piece);
                         void DisplayPiece(Piece piece);
                        bool UpdateBPlusTree(int colNum);
                        void ShowFirstFewPieces();

            private:
                        int mFp;
                        Piece piecesArray[maxLineNum];
                        int64_t lineNum;
                        static Sheet *mSheet; // for the sake of consistence in  threads
                        pthread_mutex_t *mmutexFIndInsertSheet;
                        static pthread_mutex_t *mmutexGetSheet;
};


