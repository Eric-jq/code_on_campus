#pragma once

#include<stdint.h> // this is for int64_t
//#include <vector>
#include <limits>
#include <utility>
#define BPlusTreeM 2

typedef struct InfoNode{
        int64_t val;  // the value of certain column
        int64_t lineNum; // the primary key
}InfoNode;

typedef struct BPlusTreeNode
{
        // InfoNode InfoNodes[BPlusTreeM*2];  // key
       //std:: vector<std::pair< int64_t, int64_t>> infoNodes;  // infoNodes.first =  val, infoNodes.lineNum = lineNum
       // array pointers
        InfoNode infoNodes[BPlusTreeM*2+1];
        struct BPlusTreeNode *children[BPlusTreeM*2+2]; 
        bool IsLeaf;
        int keyCount;
        struct BPlusTreeNode * leftBrother;
        struct BPlusTreeNode * rightBrother;
}BPlusTreeNode;
