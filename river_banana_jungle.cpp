#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
// Block structure 
struct Block 
{ 
    int index; 
    string data;
    long timestamp;
    string prev_hash; 
    string hash; 
  
    // Constructor 
    Block(int idx, string d, long ts, string prev_h, string h) 
    { 
        index = idx; 
        data = d;
        timestamp = ts;
        prev_hash = prev_h; 
        hash = h; 
    } 
}; 
  
// Blockchain class 
class Blockchain 
{ 
    vector<Block> chain; 
  
    public: 
    Blockchain(); 
    void addBlock(Block); 
    void showChain(); 
}; 
 
// Constructor 
Blockchain::Blockchain() 
{ 
    Block b(0, "Genesis", 1546578744, "0", "0"); 
    chain.push_back(b); 
} 
  
// Create a new block 
void Blockchain::addBlock(Block newBlock) 
{ 
    // Get index of last block 
    int idx = chain.back().index + 1; 
  
    // Create a string with previous hash 
    string prev_hash = chain.back().hash; 
  
    // Create a hash for the new block 
    string new_hash = newBlock.data + to_string(newBlock.timestamp) + prev_hash; 
  
    // Create new block 
    Block b(idx, newBlock.data, newBlock.timestamp, prev_hash, new_hash); 
  
    // Add the block to the chain 
    chain.push_back(b); 
} 
  
// Display the blockchain 
void Blockchain::showChain() 
{ 
    for (auto b : chain) 
    { 
        cout << "Index: "<< b.index << endl; 
        cout << "Data: "<< b.data << endl; 
        cout << "Timestamp: " << b.timestamp << endl;
        cout << "Previous Hash: " << b.prev_hash << endl;
        cout << "Hash: " << b.hash << endl;
        cout << "\n"; 
    } 
} 
  
// Main function 
int main() 
{ 
    // Create a blockchain 
    Blockchain bc; 
  
    // Data to be inserted 
    vector<string> data = {"Block1", "Block2", "Block3"}; 
  
    // Add blocks 
    for (int i = 0; i < data.size(); i++) 
    { 
        Block newBlock(i+1, data[i], 1546578744, "0", "0"); 
        bc.addBlock(newBlock); 
    } 
  
    // Display the chain 
    bc.showChain(); 
  
    return 0; 
}