#include<iostream>
#include "BPlusTree.h"
using namespace std;

void displayBPlusTree(BPlusTreeNode *root){
            cout<<root->infoNodes->val<<endl;
            if(!root->IsLeaf){
                        for(int i=0;i<root->keyCount;i++){
                                    displayBPlusTree(root->children[i]);
                        }
            }
}

int main(){
          const int testNum = 6;
          BPlusTree* tree = new BPlusTree;
          BPlusTreeNode *root = tree->getBPlusTreeNode();

           InfoNode testInfoNodes[testNum];
           
           int64_t keyValue[] = {5,8,10,15,16,17,18,6,9,19,20,21,22,7};
            for(int i=0;i<testNum;i++){
                        testInfoNodes->val = i;
                        testInfoNodes->lineNum = i;
                        tree->insertNode(root,testInfoNodes[i]);
            }
             displayBPlusTree(root );
}