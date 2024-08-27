#ifndef MERKLETREE_HPP
#define MERKLETREE_HPP

#include <string>
#include <vector>
#include "Block.hpp"

template <typename Data>
struct MerkleNode
{
    Data data;
    MerkleNode *left;
    MerkleNode *right;
    MerkleNode *parent;
};

template <typename Data>
class MerkleTree
{
private:
    MerkleNode<Data> *root;

    
    MerkleNode<Data> *createNode(const Data &data);
    void deleteTree(MerkleNode<Data> *node);
    void buildTree(const std::vector<Data> &dataBlocks);
    MerkleNode<Data> *buildTreeRec(const std::vector<MerkleNode<Data> *> &nodes);

public:
    MerkleTree(const std::vector<Data> &dataBlocks);
    ~MerkleTree();
    std::string getRootHash() const;
    void printTree() const;

    void printNode(MerkleNode<Data> *node, int level) const;
};


#endif
