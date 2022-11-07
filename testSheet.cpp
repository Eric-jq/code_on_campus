#include<iostream>
#include "BPlusTree.h"
#include "Sheet.h"
#include<vector>
using namespace std;

int main(){
            Sheet* msheet=Sheet::GetSheet();
            msheet->FindPieces(0,100);
            msheet->InsertPiece();
            delete(msheet);
}