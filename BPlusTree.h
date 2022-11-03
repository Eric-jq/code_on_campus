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
#define maxFindNum 10
#define filePathStoreBPlusTree "storeBplusTree_"
// #define colOutOfRange 0
// #define rootNull 1
// #define rootVerifiedOk 2

class BPlusTree{
        public:
                        BPlusTree();
                        BPlusTreeNode *IntialBPlusTree();
                        BPlusTreeNode *getBPlusTreeNode();
                        BPlusTreeNode*  insertNode(int colNum, InfoNode newInfoNode);
                        void  displayBPlusTree(int colNum);
                        // std::vector<int64_t> findSingleValue(BPlusTreeNode* root, int64_t val);
                       // std:: vector<int64_t>findScopeValue(BPlusTreeNode* root, int64_t valMin, int64_t valMax);
                       bool  findSingleValue(int colNum, int64_t val, std::vector<int64_t>&ans);
                        void findScopeValue(BPlusTreeNode* root, int64_t valMin, int64_t valMax, std:: vector<int64_t>&ans);
		bool storeBPlusTree(BPlusTreeNode* root, int col);
                        bool storeBPlusNode(int fd, BPlusTreeNode* root);
                        BPlusTreeNode *readBPlusTree(int col);
                        

                        void read(int col);
        private:
                        bool VerifyColNum(int &colNum);
                        bool splitNodes(BPlusTreeNode *nodeSon, BPlusTreeNode *nodeFather, int cur); // prerequisite: fatherNode.keyCount < BPlussTreeM
                        bool insertNodeNotRoot(BPlusTreeNode *node, InfoNode newInfoNode);
                        void displayRecursive(BPlusTreeNode *root);
                        BPlusTreeNode *readBPlusNode(int fd, BPlusTreeNode * node);
                        BPlusTreeNode *roots[MaxAttributeNumber+1];
                        
};
