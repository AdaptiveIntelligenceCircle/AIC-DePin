#pragma once
#include <unordered_map>

#include "node_identity.h"
using namespace std; 

class PeerRegistry
{
    public: 
    void register_candidate(const NodeIdentity&); 
    bool is_known(const string &node_id)const; 
}; 