#pragma once
#include <string> 

using namespace std; 

namespace aic :: network :: discovery
{
    enum class NodeType
    {
        Validator, 
        Worker, 
        Observer, 
        Bootstrap
    }; 

    struct NodeIdentity
    {
        string node_id; 
        string public_key; 
        string capability_tag;
        
        NodeType type; 
        double reputation = 0.5; 
        bool trusted = false; 

        bool operator ==(const NodeIdentity &other) const 
        {
            return node_id == other.node_id; 
        }
    }; 
}