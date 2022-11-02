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

BPlusTreeNode *BPlusTree::IntialBPlusTree(){

            BPlusTreeNode * BNode = getBPlusTreeNode();
            BNode->leftBrother = BNode;
            BNode->rightBrother = BNode;
            
            return BNode;
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
                        newNodeSon->rightBrother = nodeSon->rightBrother;
                        newNodeSon->rightBrother->leftBrother = newNodeSon;
                        newNodeSon->leftBrother = nodeSon;
                        nodeSon->rightBrother = newNodeSon;
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

 BPlusTreeNode* BPlusTree:: insertNode(BPlusTreeNode *root, InfoNode newInfoNode){
            if(root == nullptr){
                        std::cout<<"Fail to Insert, since the Root is empty!"<<std::endl;
                        return nullptr;
            }
            if(root->keyCount == 2*BPlusTreeM+1){
                        BPlusTreeNode *newRoot = getBPlusTreeNode();
                        if(newRoot == nullptr){
                                    std::cout<<"Fail to generate a new root!"<<std::endl;
                        }                                                                                                                                                                                                                                                                                                                                                                         
                        newRoot->IsLeaf = false;
                        newRoot->keyCount = 0;
                        newRoot->children[0] = root;
                        if(!splitNodes(root, newRoot,0)){
                                    std::cout<<"Fail to Split the root!"<<std::endl;
                                    return nullptr;
                        }
                        if(!insertNodeNotRoot(newRoot,newInfoNode)){
                                    std::cout<<"Fail to Insert the root!"<<std::endl;
                                    return nullptr;
                        }
                        return newRoot;
            } 
            else{
                       if(!insertNodeNotRoot(root,newInfoNode)){
                                    std::cout<<"Fail to Insert the root!"<<std::endl;
                         }    
            }
              
            return root;
 }

//  void BPlusTree::findSingleValue(BPlusTreeNode* root, int64_t val,std::vector<int64_t>&ans){
//             if(root == nullptr){
//                          std::cout<<"Fail yo find the value: the root is NULL!"<<std::endl;
//                          return ;
//             }
//             // find the leaf node
//             BPlusTreeNode* nodeTemp = root;
           
//             while(!nodeTemp->IsLeaf){
//                         int cur =nodeTemp->keyCount-1;
//                         while(cur>=0 && nodeTemp->infoNodes[cur].val>=val){
//                                     cur--;
//                         }
//                         nodeTemp = nodeTemp->children[cur+1];
//             }
//            ans.reserve(maxFindNum+1);
//            while(nodeTemp!=nullptr){
//                        int count = 0;
//                         for(int cur =0;cur<nodeTemp->keyCount&& count<maxFindNum;cur++){
//                                     std::cout<<"for test count: "<<count<<std::endl;
//                                     if(nodeTemp->infoNodes[cur].val == val){
//                                                 ans.emplace_back(nodeTemp->infoNodes[cur].lineNum);
//                                                 count++;                                        
//                                     }
//                                     else if(val < nodeTemp->infoNodes[cur].val){
//                                                 return ;
//                                     }
//                         }
//                         if(count == maxFindNum){
//                                     std::cout<<"The number of the result reaches the maximum! Only maxFindNum pieces are returned!"<<std::endl;
//                                     return ;
//                         }
//                         nodeTemp = nodeTemp->leftBrother;
//            }
//  }

// void BPlusTree::findScopeValue(BPlusTreeNode* root, int64_t valMin, int64_t valMax, std:: vector<int64_t>&ans){
//             if(root==nullptr){
//                         std::cout<<"Fail yo find the value: the root is NULL!"<<std::endl;
//                         return ;
//             }
//             BPlusTreeNode* nodeMin =  root;
//             BPlusTreeNode* nodeMax = root;
//             while(!nodeMin->IsLeaf){
//                         int cur =nodeMin->keyCount-1;
//                         while(cur>=0 && nodeMin[cur].infoNodes[cur].val>=valMin){
//                                     cur--;
//                         }
//                         nodeMin = nodeMin->children[cur+1];
//             }
//             while(!nodeMax->IsLeaf){
//                         int cur =nodeMax->keyCount-1;
//                         while(cur>=0 && nodeMax[cur].infoNodes[cur].val>valMax){
//                                     cur--;
//                         }
//                         nodeMax = nodeMax->children[cur+1];
//             }
//             ans.reserve(maxFindNum+1);
//             bool flagInMinNode = true;
//             int count = 0;
//             while(nodeMin != nodeMax){
//                        int nodeKeycount = nodeMin->keyCount;
//                         if(flagInMinNode){
//                                     for(int i=0;i<nodeKeycount;i++){
//                                                 if(nodeMin->infoNodes[i].val == valMin){
//                                                             for(int j=i;j<nodeKeycount&&count<maxFindNum;j++){
//                                                                         ans.emplace_back(nodeMin->infoNodes[i].lineNum);
//                                                                         count++;
//                                                             }
//                                                 }
//                                     }
//                                     flagInMinNode = false;
//                         }
//                         else{
//                                     for(int i=0;i<nodeKeycount && count<maxFindNum;i++){
//                                                 ans.emplace_back(nodeMin->infoNodes[i].lineNum);
//                                     }
//                         }
//                         if(count == maxFindNum){
//                                     return;
//                         }
//                         nodeMin = nodeMin->leftBrother;
//             }
//             // nodeMax/nodeMin->IsLeaf = true
//             for(int cur =0;cur<nodeMin->keyCount&& count<maxFindNum;cur++){
//                         std::cout<<"for test count: "<<count<<std::endl;
//                         if(nodeMin->infoNodes[cur].val <= valMax){
//                                     ans.emplace_back(nodeMin->infoNodes[cur].lineNum);
//                                     count++; 
//                         }                                                 
//             }
//             if(count == maxFindNum){
//                         std::cout<<"The number of the result reaches the maximum! Only maxFindNum pieces are returned!"<<std::endl;
//                         return ;
//             }
// }

// bool BPlusTree::storeBPlusNode(int fd, BPlusTreeNode* node){
//             // storeBPlusTree has assured fd!=-1 && root!=nullptr
//             if(fd<0){
//                         std::cout<<"Fail to write the node:: fail to open the file!"<<std::endl;
//                         return false;
//             }
//             if(node==nullptr){
//                         std::cout<<"Fail to write the node:: The node is empty!"<<std::endl;
//                         return false;
//             }
//              if (write(fd, node, sizeof(node)) == -1){
// 		std::cout<<"Fail to write the node"<<std::endl;
// 		return false;
// 	}
//             if(!node->IsLeaf){
//                         for(int i=0;i<node->keyCount;i++){
//                                     if(!storeBPlusNode(fd, node->children[i])){
//                                                 return false;
//                                     }
//                         }
//             }
//             return true;
// }

// bool BPlusTree::storeBPlusTree(BPlusTreeNode* root, int col){
//             if(root == nullptr){
//                         std::cout<<"Fail to store the Tree: the root is NULL!"<<std::endl;
//                         return false;
//             }
//             std::string filePath =  filePathStoreBPlusTree + std::to_string(col);
//              std::ifstream f(filePath.c_str());

//             if(f.good()){  // the file exists, delete it val
//                         if(remove(filePath.c_str()) != 0 ){
//                                     std::cout<<"Fail to remove !"<<std::endl;
//                                      return false;
//                         }
//             }
//             //int fd = std::open(filePath.c_str(), O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
//             // Anyone has access to the file
//             int fd = open(filePath.c_str(),  O_CREAT | O_EXCL |O_RDWR, S_IRUSR | S_IWUSR);
//             if (fd == -1){
// 		std::cout<<"Fail to generate a new file: "<<strerror(errno)<<std::endl;
//                        // std::cout<<"Open error"<<std::endl;
// 		 return false;
// 	}
//             if(close(fd)){
//                         std::cout<<"Fail to close the  file: "<<strerror(errno)<<std::endl;
//                          return false;
//             }
// }

//  BPlusTreeNode *readBPlusNode(int fd, BPlusTreeNode * node){
//              if(fd<0){
//                         std::cout<<"Fail to read the node:fail to open the file!"<<std::endl;
//                         return nullptr;
//             }
//             if(node==nullptr){
//                         std::cout<<"Fail to read the node:the node is empty!"<<std::endl;
//                         return nullptr;
//             }
//             BPlusTreeNode *newNode = getBPlusTreeNode();
//             if(read(fd,newNode,sizeof(newNode))==-1){
//                         std::cout<<"Fail to read the node: the file is unreadable!"<<std::endl;
//             }
//             if(!newNode->IsLeaf){
//                         for(int i=0;i<newNode->keyCount;i++){
//                                     newNode->children[i] = readBPlusNode(fd);
//                         }
//             }
//             else{
//                         return newNode;
//             }
//             return newNode;
//  }

//  BPlusTreeNode *readBPlusTree(int col){
//             std::string filePath =  filePathStoreBPlusTree + std::to_string(col);
//             std::ifstream f(filePath.c_str());
//             if(!f.good()){  // the file doesn't exists
//                        return nullptr;
//             }
//             int fd = open(filePath.c_str(),  O_RDWR, S_IRUSR | S_IWUSR);
//             if(fd ==-1){
//                         std::cout<<"Fail to open the file"<<std::endl;
//                         return nullptr;
//             }
//             BPlusTreeNode *root = readBPlusNode(int col);
//             close(fd);
//             return root;
//  }



            