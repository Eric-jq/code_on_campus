#include<iostream>
#include "BPlusTree.h"
#include "Sheet.h"
#include<vector>
using namespace std;

int main(){
            Sheet* msheet=Sheet::GetSheet();
            //msheet->FindPieces(22,1);
            // msheet->mBplusTree->displayBPlusTree(1);
            // cout<<"Bfore testBrothers"<<endl;
            //msheet->mBplusTree->testBrothers(1);
         
            //msheet->ShowFirstFewPieces();
            // cout<<"BeforeFIndPIece"<<endl;
            msheet->mBplusTree->displayBPlusTree(1);
            // cout<<"AfterFIndPIece"<<endl;
            msheet->InsertPiece();
             msheet->mBplusTree->displayBPlusTree(1);
             msheet->FindPieces(-90,261,1);
            delete(msheet);
}