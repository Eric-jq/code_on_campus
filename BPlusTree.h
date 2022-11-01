#pragma once

#include"node.h"
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

class BPlusTree{
        public:
                        BPlusTreeNode *IntialBPlusTree();
                        BPlusTreeNode *getBPlusTreeNode();
                        BPlusTreeNode*  insertNode(BPlusTreeNode *node, InfoNode newInfoNode);
                       
                        // std::vector<int64_t> findSingleValue(BPlusTreeNode* root, int64_t val);
                       // std:: vector<int64_t>findScopeValue(BPlusTreeNode* root, int64_t valMin, int64_t valMax);
                       void  findSingleValue(BPlusTreeNode* root, int64_t val, std::vector<int64_t>&ans);
                        void findScopeValue(BPlusTreeNode* root, int64_t valMin, int64_t valMax, std:: vector<int64_t>&ans);
		bool storeBPlusTree(BPlusTreeNode* root, int col);
                        bool storeBPlusNode(int fd, BPlusTreeNode* root);
                        BPlusTreeNode *readBPlusTree(int col);
                        

                        void read(int col);
        private:
                        bool splitNodes(BPlusTreeNode *nodeSon, BPlusTreeNode *nodeFather, int cur); // prerequisite: fatherNode.keyCount < BPlussTreeM
                        bool insertNodeNotRoot(BPlusTreeNode *node, InfoNode newInfoNode);
                        BPlusTreeNode *readBPlusNode(int fd, BPlusTreeNode * node);
                        
};
