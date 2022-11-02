#include<iostream>
#include "BPlusTree.h"
using namespace std;

void displayBPlusTree(BPlusTreeNode *root){
            cout<<"count: "<<root->keyCount<<endl;
            if(root->IsLeaf){
                        for(int i=0;i<root->keyCount;i++){
                                    cout<<root->infoNodes[i].val<<endl;
                        }
            }
            
            if(!root->IsLeaf){
                        for(int i=0;i<=root->keyCount;i++){
                                    displayBPlusTree(root->children[i]);
                        }
            }
}

int main(){
          const int testNum = 9;
          BPlusTree* tree = new BPlusTree;
          BPlusTreeNode *root = tree->IntialBPlusTree();

           InfoNode testInfoNodes[2* testNum];
           
           int64_t keyValue[] = {5,8,10,15,16,17,18,6,9,19,20,21,22,7};
//             for(int i=0;i<=testNum;i++){
//                         testInfoNodes[i].val = i;
//                         testInfoNodes[i].lineNum = i;
//                         root = tree->insertNode(root,testInfoNodes[i]);
//             }
              for(int i=0;i<=testNum;i++){
                        testInfoNodes[i].val = keyValue[i];
                        testInfoNodes[i].lineNum = i ;
                         root = tree->insertNode(root,testInfoNodes[i]);
              }
            // testInfoNodes[8].val = keyValue[8];
            // testInfoNodes[8].lineNum = 8 ;
            // root = tree->insertNode(root,testInfoNodes[8]);
           
            displayBPlusTree(root );
             delete(root);
             delete(tree);
}