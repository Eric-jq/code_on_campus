#pragma once

#include"node.h"
#include"piece.h"
#include<iostream>
#include <fstream>
#include <cstring>
#include <cstdio> 
#include<string.h>
#include<fcntl.h>
#include<vector>
#include<unistd.h>
#include <sys/stat.h> 　
#include <sys/types.h>

#define maxFindNum 10
#define StoreBPlusDir  "../BPlusTreeFile"
#define filePathStoreBPlusTree "../BPlusTreeFile/storeBplusTree_"
// #define colOutOfRange 0
// #define rootNull 1
// #define rootVerifiedOk 2

class BPlusTree{
        public:
                        BPlusTree();
                        ~BPlusTree();
                        bool VerifyColNum(int colNum);             
                        bool  insertNode(int colNum, InfoNode newInfoNode);
                        bool  insertNode(int colNum, Piece piece);
                        bool  findSingleValue(int64_t val, int colNum, std::vector<int64_t>&ans);
                        bool findScopeValue(int64_t valMin, int64_t valMax, int colNum, std:: vector<int64_t>&ans);
                        bool InitializeBPlussTree();
                        bool UpdateBPlusTree(Piece piece);

                        void  displayBPlusTree(int colNum);
                        bool testBrothers(int colNUm);
                      
        private:
                        bool storeBPlusNode(int fp, BPlusTreeNode* root);
		bool storeBPlusTree(int colNum);
                        BPlusTreeNode*readBPlusNode(int fp, BPlusTreeNode *&leftLeavenode);
                        bool readBPlusTree(int col);
                        BPlusTreeNode *getBPlusTreeNode();
                        InfoNode getInfoNode(int colNum, Piece piece);
                        bool GenerateLeaveBrother(BPlusTreeNode * originalNode, BPlusTreeNode *newNode);
                        bool splitNodes(BPlusTreeNode *nodeSon, BPlusTreeNode *nodeFather, int cur); // prerequisite: fatherNode.keyCount < BPlussTreeM
                        bool insertNodeNotRoot(BPlusTreeNode *node, InfoNode newInfoNode);
                        void displayRecursive(BPlusTreeNode *root);
                          bool testBothersRecursive(BPlusTreeNode * nodeLeave);
                        BPlusTreeNode *roots[MaxAttributeNumber+1];                      
};
