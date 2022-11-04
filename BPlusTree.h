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
                        bool VerifyColNum(int colNum);
                        //BPlusTreeNode *IntialBPlusTree();
                        BPlusTreeNode *getBPlusTreeNode();
                        InfoNode getInfoNode(int colNum, Piece piece);
                        bool  insertNode(int colNum, InfoNode newInfoNode);
                        bool  insertNode(int colNum, Piece piece);
                        void  displayBPlusTree(int colNum);
                        // std::vector<int64_t> findSingleValue(BPlusTreeNode* root, int64_t val);
                       // std:: vector<int64_t>findScopeValue(BPlusTreeNode* root, int64_t valMin, int64_t valMax);
                        bool  findSingleValue(int64_t val, int colNum, std::vector<int64_t>&ans);
                        bool findScopeValue(int64_t valMin, int64_t valMax, int colNum, std:: vector<int64_t>&ans);
		// bool storeBPlusTree(int col);
                        // bool storeBPlusNode(int fd, BPlusTreeNode* root);
                        // BPlusTreeNode *readBPlusTree(int col);
                        // bool BuildBPlussTree(Piece piecesArray[], int lineNum);
                        // bool InitializeBPlussTree();
                        // bool UpdateBPlusTree(Piece piece);
        private:
                        
                        bool splitNodes(BPlusTreeNode *nodeSon, BPlusTreeNode *nodeFather, int cur); // prerequisite: fatherNode.keyCount < BPlussTreeM
                        bool insertNodeNotRoot(BPlusTreeNode *node, InfoNode newInfoNode);
                        void displayRecursive(BPlusTreeNode *root);
                        BPlusTreeNode *readBPlusNode(int fd, BPlusTreeNode * node);
                        BPlusTreeNode *roots[MaxAttributeNumber+1];                      
};
