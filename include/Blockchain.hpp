#ifndef BLOCKCHAIN_HPP
#define BLOCKCHAIN_HPP

#include "Block.hpp"
#include <list>

template <typename Data>
class Blockchain
{
public:
    
    explicit Blockchain(const Block<Data> &genesisBlock); 
    Blockchain();                                                


    void addBlock(const Block<Data> &block); 
    Block<Data> getLatestBlock() const;     

private:
    std::list<Block<Data>> chain; 
};

#endif 
