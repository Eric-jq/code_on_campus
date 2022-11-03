#pragma once

#include "piece.h"
#include "BPlusTree.h"
#include <time.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#define rawLineNUm 1000
#define maxLineNum 1000000
#define SheetFilePath "***"

class Sheet{
            public:
                        Sheet();
                        bool SetRawSheet();
                        Piece GetNewSheet(); 
                        bool AppendSheet(Piece piece);
            private:
                        int mFp;
                        Piece piecesArray[maxLineNum];
                        int64_t lineNum;
                        BPlusTree *mBplusTree;
                        static Sheet *mSheet; // for the sake of consistence in  threads
};


