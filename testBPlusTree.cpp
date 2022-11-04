#include<iostream>
#include "BPlusTree.h"
#include<vector>
using namespace std;

int main(){
          const int testNum = 24;
          BPlusTree* tree = new BPlusTree;
          //BPlusTreeNode *root = tree->IntialBPlusTree();

           InfoNode testInfoNodes[2* testNum];
           
           int64_t keyValue[] = {5,8,10,15,16,17,18,6,9,19,20,21,22,7,8,5,6,7,2,10,2,3,6,4,7};
//             for(int i=0;i<=testNum;i++){
//                         testInfoNodes[i].val = i;
//                         testInfoNodes[i].lineNum = i;
//                         root = tree->insertNode(root,testInfoNodes[i]);
//             }
              for(int i=0;i<=testNum;i++){
                        testInfoNodes[i].val = keyValue[i];
                        testInfoNodes[i].lineNum = i ;
                        tree->insertNode(1,testInfoNodes[i]);
              }
            // testInfoNodes[8].val = keyValue[8];
            // testInfoNodes[8].lineNum = 8 ;
            // root = tree->insertNode(root,testInfoNodes[8]);
           tree->displayBPlusTree(1);
           vector<int64_t> ans;
           tree->findSingleValue(5,1,ans);
           for(int i=0;i<ans.size();i++){
                       cout<<"ans: "<<ans[i]<<" ";
           }
             delete(tree);
}