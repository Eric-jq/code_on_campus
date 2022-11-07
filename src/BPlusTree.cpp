#pragma once
#include "BPlusTree.h"

BPlusTreeNode* BPlusTree::getBPlusTreeNode(){
            BPlusTreeNode *Bnode =  (BPlusTreeNode *)malloc(sizeof(BPlusTreeNode));
            if(Bnode == nullptr){
                        std::cout<<"Fail to get a new BPlusTreeNode"<<std::endl;
                        return nullptr;
            }
            for(int i=0;i<2*BPlusTreeM;i++){
                       // Bnode->infoNodes[i] = (InfoNode *)malloc(sizeof(InfoNode ));
                        Bnode->infoNodes[i].val =std::numeric_limits<int64_t>::min();
                        Bnode->infoNodes[i].lineNum = std::numeric_limits<int64_t>::min();;
                        //Bnode->infoNodes[i].emplace_back(-1,-1);

            }
            for(int i=0;i<2*BPlusTreeM+1;i++){
                        Bnode->children[i] = nullptr;
            }
            Bnode->IsLeaf = true;
            Bnode->keyCount =0;
            Bnode->leftBrother = nullptr;
            Bnode->rightBrother = nullptr;
            return Bnode;
 }

 InfoNode BPlusTree::getInfoNode(int colNum, Piece piece){
             if(!VerifyColNum(colNum)){
                         std::cout<<"Error: fail to get infoNode"<<std::endl;
                         //return ;
             }
             colNum--;
             InfoNode infoNode;
             infoNode.lineNum = piece.lineNum;
             infoNode.val = piece.arrtibute[colNum];
             return infoNode;
 }

// BPlusTreeNode *BPlusTree::IntialBPlusTree(){

//             BPlusTreeNode * BNode = getBPlusTreeNode();
//             BNode->leftBrother = BNode;
//             BNode->rightBrother = BNode;
            
//             return BNode;
// }

 bool BPlusTree::VerifyColNum(int colNum){
            if(colNum<1 || colNum>100){
                        std::cout<<"Error: the colNum is out of range"<<std::endl;
                        return false;
            }

            if(roots[colNum-1] == nullptr){
                        std::cout<<"Error: The root is empty"<<std::endl;
                        return false;
            }
            return true;
}

BPlusTree::BPlusTree(){
            for(int i=0;i<=MaxAttributeNumber;i++){
                        roots[i] = getBPlusTreeNode();
            }
}
BPlusTree::~BPlusTree(){
            for(int i=1;i<=MaxAttributeNumber;i++){
                       if(!storeBPlusTree(i)){
                                    std::cout<<"Fatal Error: Fail to store the Tree:!"<<std::endl;
                                    break;
                       }
                       std::cout<<"~BPlusTree"<<std::endl;
            }
}


  bool BPlusTree:: GenerateLeaveBrother(BPlusTreeNode * originalNode, BPlusTreeNode *newNode){
            if(originalNode == nullptr){
                        std::cout<<"Error:  Fail to generate brothers since the originalNode is NULL!"<<std::endl;
                        return false;
            }
             if(newNode == nullptr){
                        std::cout<<"Error: Fail to generate brothers since the newNode is NULL!"<<std::endl;
                        return false;
            }
            if(originalNode->rightBrother == nullptr){
                        originalNode->rightBrother = newNode;
                        newNode->leftBrother = originalNode;
                        return true;
            }
            newNode->rightBrother = originalNode->rightBrother;
            originalNode->rightBrother->leftBrother = newNode;
            originalNode->rightBrother = newNode;
            newNode->leftBrother = originalNode;
            return true;
  }

bool BPlusTree::splitNodes(BPlusTreeNode *nodeSon, BPlusTreeNode *nodeFather, int cur){
           if(nodeSon == nullptr){
                       std::cout<<"This the nodeSon is NULL!"<<std::endl;
                       return false; 
           }
            if(nodeFather == nullptr){
                        std::cout<<"This the nodeFather is NULL!"<<std::endl;
                        return false;
            }
            BPlusTreeNode *newNodeSon =  getBPlusTreeNode();
            // start to transfer the left half to newNodeSon
            newNodeSon->IsLeaf = nodeSon->IsLeaf;
           //  int point = nodeSon->keyCount;
           
            if(!newNodeSon->IsLeaf){  // Internal Node: children copy is needed
                        for(int i=0; i<=BPlusTreeM;i++){
                                    newNodeSon->children[i] = nodeSon->children[i+BPlusTreeM+1];
                        }
                        for(int i=0;i<BPlusTreeM ;i++){
                                    newNodeSon->infoNodes[i] = nodeSon->infoNodes[i+BPlusTreeM+1];
                        }
                        newNodeSon->keyCount = BPlusTreeM;
            }
            else{
                        for(int i=0;i<=BPlusTreeM ;i++){
                                    newNodeSon->infoNodes[i] = nodeSon->infoNodes[i+BPlusTreeM];
                        }
                        //if(nodeSon->leftBrother == nullptr && nodeSon->leftBrother)
                        // newNodeSon->rightBrother = nodeSon->rightBrother;
                        // newNodeSon->rightBrother->leftBrother = newNodeSon;
                        // newNodeSon->leftBrother = nodeSon;
                        // nodeSon->rightBrother = newNodeSon;
                        if(!GenerateLeaveBrother(nodeSon,newNodeSon)){
                                     std::cout<<"Error: fail to split nodes!"<<std::endl;
                                    return false;
                        }
                        newNodeSon->keyCount = BPlusTreeM+1;
            }
            nodeSon->keyCount = BPlusTreeM;

            for(int i=nodeFather->keyCount;i>cur;i--){
                        nodeFather->infoNodes[i] = nodeFather->infoNodes[i-1];
            }
            nodeFather->infoNodes[cur] = newNodeSon->infoNodes[0];
            for(int i=nodeFather->keyCount;i>cur;i--){
                        nodeFather->children[i+1] = nodeFather->children[i];
            }
            nodeFather->children[cur+1] = newNodeSon;
            nodeFather->keyCount++;
            return true;
}

bool BPlusTree::insertNodeNotRoot(BPlusTreeNode *node, InfoNode newInfoNode){
            if(node == nullptr){
                        std::cout<<"The node is empty"<<std::endl;
                        return false;
            }
            if(node->IsLeaf){
                        int cur = node->keyCount;
                       for(;node->infoNodes[cur-1].val > newInfoNode.val && cur>=1 ;cur--){
                                   node->infoNodes[cur] = node->infoNodes[cur-1];
                       }
                       node->infoNodes[cur] = newInfoNode;
                       node->keyCount++;
                       return true;
            }
            else{
                        int cur = node->keyCount;
                        for(;node->infoNodes[cur-1].val > newInfoNode.val && cur>=1;cur--){}
                        if(node->children[cur]->keyCount == 2* BPlusTreeM+1){ // full, then split
                                    bool flag = splitNodes(node->children[cur],node,cur);
                                    if(!flag){
                                                return false;
                                    }
                                    if(node->infoNodes[cur].val<newInfoNode.val ){ // right child of the new node
                                                cur++;
                                    }
                       }
                      return  insertNodeNotRoot(node->children[cur], newInfoNode);
            }

}

bool BPlusTree:: insertNode(int colNum, InfoNode newInfoNode){
            if(!VerifyColNum(colNum)){
                        std::cout<<"Fail to generate a new root!"<<std::endl;
                        return false;
            }
            colNum--;
            if(roots[colNum]->keyCount == 2*BPlusTreeM+1){
                        BPlusTreeNode *newRoot = getBPlusTreeNode();
                        if(newRoot == nullptr){
                                    std::cout<<"Fail to generate a new root!"<<std::endl;
                                    return false;
                        }                                                                                                                                                                                                                                                                                                                                                                         
                        newRoot->IsLeaf = false;
                        newRoot->keyCount = 0;
                        newRoot->children[0] = roots[colNum];
                        if(!splitNodes(roots[colNum], newRoot,0)){
                                    std::cout<<"Fail to Split the root!"<<std::endl;
                                    return false;
                        }
                        if(!insertNodeNotRoot(newRoot,newInfoNode)){
                                    std::cout<<"Fail to Insert the root!"<<std::endl;
                                    return false;
                        }
                        roots[colNum] = newRoot;
                        return true;
            } 
            else{
                       if(!insertNodeNotRoot(roots[colNum],newInfoNode)){
                                    std::cout<<"Fail to Insert the root!"<<std::endl;
                                    return false;
                         }    
            }
              
            return true;
 }

bool  BPlusTree::insertNode(int colNum, Piece piece){
               if(!VerifyColNum(colNum)){
                        std::cout<<"Fail to generate a new root!"<<std::endl;
                        return false;
            }
            InfoNode newInfoNode = getInfoNode(colNum,piece);
            colNum--;
            if(roots[colNum]->keyCount == 2*BPlusTreeM+1){
                        BPlusTreeNode *newRoot = getBPlusTreeNode();
                        if(newRoot == nullptr){
                                    std::cout<<"Fail to generate a new root!"<<std::endl;
                                    return false;
                        }                                                                                                                                                                                                                                                                                                                                                                         
                        newRoot->IsLeaf = false;
                        newRoot->keyCount = 0;
                        newRoot->children[0] = roots[colNum];
                        if(!splitNodes(roots[colNum], newRoot,0)){
                                    std::cout<<"Fail to Split the root!"<<std::endl;
                                    return false;
                        }
                        if(!insertNodeNotRoot(newRoot,newInfoNode)){
                                    std::cout<<"Fail to Insert the root!"<<std::endl;
                                    return false;
                        }
                        roots[colNum] = newRoot;
                        return true;
            } 
            else{
                       if(!insertNodeNotRoot(roots[colNum],newInfoNode)){
                                    std::cout<<"Fail to Insert the root!"<<std::endl;
                                    return false;
                         }    
            }
              
            return true;
}

void BPlusTree:: displayBPlusTree(int colNum){
            if(!VerifyColNum(colNum)){
                         std:: cout<<"Error: Fail to display"<<std::endl;
                         return;
            }
            colNum--;
           displayRecursive(roots[colNum]);
}

void BPlusTree::displayRecursive(BPlusTreeNode *root){
            if(root == nullptr){
                        std:: cout<<"Fail to display, the node is empty!"<<std::endl;
            }
            std:: cout<<"count: "<<root->keyCount<<std::endl;
            if(!root->IsLeaf){

                        for(int i=0;i<=root->keyCount;i++){
                                    displayRecursive(root->children[i]);
            }
            }else{
                         for(int i=0;i<root->keyCount;i++){
                                      std:: cout<<root->infoNodes[i].val<<std::endl;
                         }
            }
}

bool BPlusTree::testBrothers(int colNum){
            if(!VerifyColNum(colNum)){
                         std::cout<<"Error: Fail to testBrothers"<<std::endl;
                         return false;
            }
            colNum--;
            BPlusTreeNode * nodeLeave = roots[colNum];
            while(!nodeLeave->IsLeaf){
                        nodeLeave = nodeLeave->children[0];
            }
            testBothersRecursive(nodeLeave);
            return true;
}

bool BPlusTree::testBothersRecursive(BPlusTreeNode * nodeLeave){
            if(nodeLeave == nullptr){
                         std::cout<<"Error: Fail to test BothersRevursive"<<std::endl;
                         return false;
            }
            for(int i=0;i<nodeLeave->keyCount;i++){
                        std::cout<<nodeLeave->infoNodes[i].val<<" ";
            }
            if(nodeLeave->rightBrother != nullptr){
                        testBothersRecursive(nodeLeave->rightBrother);
            }
}

bool BPlusTree::findSingleValue(int64_t val,int colNum, std::vector<int64_t>&ans){
             if(!VerifyColNum(colNum)){
                        std:: cout<<"Error: Fail to find single value"<<std::endl;
                        return false;
            }
            colNum--;
            // find the leaf node
            ans.reserve(maxFindNum+1);
            BPlusTreeNode* nodeTemp = roots[colNum];
           
            while(!nodeTemp->IsLeaf){
                        int cur =nodeTemp->keyCount-1;
                        while(cur>=0 && nodeTemp->infoNodes[cur].val>=val){
                                    cur--;
                        }
                        nodeTemp = nodeTemp->children[cur+1];
            }
           while(nodeTemp!=nullptr){
                       int count = 0;
                        for(int cur =0;cur<nodeTemp->keyCount&& count<maxFindNum;cur++){
                                    // std::cout<<"key count: "<<nodeTemp->keyCount<<std::endl;
                                    // std::cout<<"for test count: "<<count<<std::endl;
                                    if(nodeTemp->infoNodes[cur].val == val){
                                                ans.emplace_back(nodeTemp->infoNodes[cur].lineNum);
                                                count++;                                        
                                    }
                                    else if(val < nodeTemp->infoNodes[cur].val){
                                                return true ;
                                    }
                        }
                        if(count == maxFindNum){
                                    std::cout<<"The number of the result reaches the maximum! Only maxFindNum pieces are returned!"<<std::endl;
                                    return true;
                        }
                        nodeTemp = nodeTemp->rightBrother;
           }
            return true;
 }

bool BPlusTree::findScopeValue(int64_t valMin, int64_t valMax, int colNum, std:: vector<int64_t>&ans){
            if(!VerifyColNum(colNum)){
                        std:: cout<<"Error: Fail to find single value"<<std::endl;
                        return false;
            }
            colNum--;
            if(roots[colNum]==nullptr){
                        std::cout<<"Error: Fail yo find the value  since the root is NULL!"<<std::endl;
                        return false;
            }
            BPlusTreeNode* nodeMin =  roots[colNum];
            BPlusTreeNode* nodeMax = roots[colNum];
            while(!nodeMin->IsLeaf){
                        int cur =nodeMin->keyCount-1;
                        while(cur>=0 && nodeMin->infoNodes[cur].val>=valMin){
                                    cur--;
                        }
                        nodeMin = nodeMin->children[cur+1];
            }
            while(!nodeMax->IsLeaf){
                        int cur =nodeMax->keyCount-1;
                        while(cur>=0 && nodeMax->infoNodes[cur].val>valMax){
                                    cur--;
                        }
                        nodeMax = nodeMax->children[cur+1];
            }
            ans.reserve(maxFindNum+1);
            bool flagInMinNode = true;
            int count = 0;
            std::cout<<"keyCount min:"<<nodeMin->keyCount<<std::endl;
            std::cout<<"keyCount max:"<<nodeMax->keyCount<<std::endl;
            while(nodeMin != nodeMax){
                       int nodeKeycount = nodeMin->keyCount;
                        if(flagInMinNode){
                                    for(int i=0;i<nodeKeycount;i++){
                                                if(nodeMin->infoNodes[i].val >= valMin){
                                                            for(int j=i;j<nodeKeycount&&count<maxFindNum;j++){
                                                                        ans.emplace_back(nodeMin->infoNodes[j].lineNum);
                                                                        count++;
                                                            }
                                                            break;
                                                }
                                    }
                                    flagInMinNode = false;
                        }
                        else{
                                    for(int i=0;i<nodeKeycount && count<maxFindNum;i++){
                                                ans.emplace_back(nodeMin->infoNodes[i].lineNum);
                                    }
                        }
                        if(count == maxFindNum){
                                    return true;
                        }
                        nodeMin = nodeMin->rightBrother;
            }
            // nodeMax/nodeMin->IsLeaf = true
            for(int cur =0;cur<nodeMin->keyCount&& count<maxFindNum;cur++){
                        std::cout<<"for test count: "<<count<<std::endl;
                        if(nodeMin->infoNodes[cur].val <= valMax){
                                    ans.emplace_back(nodeMin->infoNodes[cur].lineNum);
                                    count++; 
                        }                                                 
            }
            if(count == maxFindNum){
                        std::cout<<"The number of the result reaches the maximum! Only maxFindNum pieces are returned!"<<std::endl;
                        return true;
            }
            return true;
}

bool BPlusTree::storeBPlusNode(int fp, BPlusTreeNode* node){
            // storeBPlusTree has assured fd!=-1 && root!=nullptr
            if( fp<0){
                        std::cout<<"Fail to write the node:: fail to open the file!"<<std::endl;
                        return false;
            }
            if(node==nullptr){
                        std::cout<<"Fail to write the node:: The node is empty!"<<std::endl;
                        return false;
            }
             if (write(fp, node, sizeof(node)) == -1){
		std::cout<<"Fail to write the node"<<std::endl;
		return false;
	}
            if(!node->IsLeaf){
                        for(int i=0;i<node->keyCount;i++){
                                    if(!storeBPlusNode(fp, node->children[i])){
                                                return false;
                                    }
                        }
            }
            return true;
}

bool BPlusTree::storeBPlusTree( int colNum){
             if(!VerifyColNum(colNum)){
                        std:: cout<<"Error: Fail to store the BPlusTree"<<std::endl;
                        return false;
            }
            colNum--;
            if(roots[colNum] == nullptr){
                        std::cout<<"Fail to store the Tree: the root is NULL!"<<std::endl;
                        return false;
            }
            std::string dirPath = StoreBPlusDir;
            if(!access(dirPath.c_str(),F_OK) == -1){ // need create a new one
                        int isCreateDir = mkdir(dirPath.c_str(), S_IRUSR | S_IWUSR | S_IXUSR | S_IRWXG | S_IRWXO);
                        if(isCreateDir == -1){
                                    std::cout<<"Error: fail to store the BPlusTree since DirCreation failed!"<<std::endl;
                                    std::cout<<"errno: "<< errno<<": "<<strerror(errno)<<std::endl;
                                    return false;
                        }
            }
            std::string filePath =  filePathStoreBPlusTree + std::to_string(colNum+1);

            // if(access(filePath.c_str(),F_OK) ){  // the file exists, delete it 
            //             if(remove(filePath.c_str()) != 0 ){
            //                         std::cout<<"Fail to remove !"<<std::endl;
            //                          return false;
            //             }
            // }
            int fp = open(filePath.c_str(),  O_CREAT |O_RDWR, S_IRUSR | S_IWUSR);
            if (fp == -1){
		std::cout<<"Fail to generate a new file: "<<strerror(errno)<<std::endl;
		 return false;
	}
           if(!storeBPlusNode(fp, roots[colNum])) ;
            if(close(fp) == -1){
                        std::cout<<"Fail to close the  file: "<<strerror(errno)<<std::endl;
                         return false;
            }
}

bool BPlusTree::readBPlusNode(int fd, BPlusTreeNode * node){
             if(fd<0){
                        std::cout<<"Error: Fail to read the node:fail to open the file!"<<std::endl;
                        return false;
            }
            if(node==nullptr){
                        std::cout<<"Error: Fail to read the node:the node is empty!"<<std::endl;
                        return false;
            }
            if(read(fd,node,sizeof(node))==-1){
                        std::cout<<"Fail to read the node: the file is unreadable!"<<std::endl;
            }
            if(!node->IsLeaf){
                        for(int i=0;i<=node->keyCount;i++){
                                    if(!readBPlusNode(fd, node->children[i])){
                                                std::cout<<"Fail to read the node: the file is unreadable!"<<std::endl;
                                                return false;
                                    }
                        }
            }
            return true;
 }

 bool BPlusTree::readBPlusTree(int colNum){
            if(!VerifyColNum(colNum)){
                        std:: cout<<"Error: Fail to read the BPlusTreeFile"<<std::endl;
                        return false;
            }
            colNum--;
            std::string filePath =  filePathStoreBPlusTree + std::to_string(colNum+1);
             std:: cout<<"readPath:"<<filePath<<std::endl;
            if(access(filePath.c_str(),F_OK)==-1 ){
                        std:: cout<<"Error: The BPlusTreeFile doesn't exist!"<<std::endl;
                        return false;

            }
            int fp = open(filePath.c_str(),  O_RDWR, S_IRUSR | S_IWUSR);
            if(fp ==-1){
                        std::cout<<"Error: Fail to open the BPlusTreeFile"<<std::endl;
                        return false;
            }
            if(!readBPlusNode(fp,roots[colNum])){
                        std::cout<<"Error: Fail to read the BPlusTreeFile"<<std::endl;
                        return false;
            }
             if(close(fp) == -1){
                        std::cout<<"Fail to close the  file: "<<strerror(errno)<<std::endl;
                         return false;
            }
            return true;
 }

bool BPlusTree::BuildBPlussTree(Piece piecesArray[],int lineNum){
            if(piecesArray == nullptr){
                        std::cout<<"Error: the pieceArray is empty"<<std::endl;
                        return false;
            }
            for(int i=1; i<=MaxAttributeNumber;i++){
                        for(int j=0;j<lineNum;j++){
                                   if(!insertNode(i,piecesArray[j])) {
                                                std::cout<<"Error: Fail to build BPlusTree!"<<std::endl;
                                                return false;
                                   }
                        }
                        if(!storeBPlusTree(i)){
                                    std::cout<<"Error: Fail to store BPlusTree!"<<std::endl;
                        }
            }
            return true;
}

bool BPlusTree::InitializeBPlussTree(){
            std::cout<<"Start to initialize the tree!"<<std::endl;
            for(int i=1;i<=MaxAttributeNumber;i++){
                        if(!readBPlusTree(i)){
                                     std::cout<<"Error: Fail to Initialize BPlusTree!"<<std::endl;
                                     return false;
                        }
            }
            return true;
}

bool BPlusTree::UpdateBPlusTree(Piece piece){
            for(int i=1;i<=MaxAttributeNumber;i++){
                        if(!insertNode(i, piece)){
                                    std::cout<<"Error: Fail to Update the BPlusTree!"<<std::endl;
                                    return false;
                        }
                        // if(!storeBPlusTree(i)){
                        //             std::cout<<"Error: Fail to Update the BPlusTree!"<<std::endl;
                        //             return false;
                        // }
            }
            return true;
}