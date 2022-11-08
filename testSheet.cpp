#include<iostream>
#include "BPlusTree.h"
#include "Sheet.h"
#include<vector>
using namespace std;

int main(){
            Sheet* msheet=Sheet::GetSheet();
            //msheet->FindPieces(22,1);
            msheet->mBplusTree->displayBPlusTree(1);
            //msheet->ShowFirstFewPieces();
            //msheet->FindPieces(383,1);
            //msheet->InsertPiece();
            delete(msheet);
}