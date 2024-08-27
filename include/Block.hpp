#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <string>
#include <MerkleTree.hpp>
#include <ctime>

template <typename Data>
class Block
{
public:
    Block()
        : index(0), nonce(0), timestamp(std::time(nullptr)) {}

    // Accessors
    std::string getMerkleRoot() const { return merkleRoot; }
    std::string getPrevHash() const { return prevHash; }
    std::string getHash() const { return hash; }

    // Methods
    void computeHash();
    void computeMerkleRoot();

    // Mutators
    void addData(const Data &data);

private:
    int index;
    std::string merkleRoot;
    std::string prevHash;
    std::string hash;
    MerkleTree<Data> merkleTree; 
    std::time_t timestamp;
};

#endif 
