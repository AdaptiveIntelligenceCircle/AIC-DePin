#pragma once 
#include "node_state.h"

namespace aic :: node 
{
    class Node
    {
    public: 
    Node(); 

    void start(); 
    void stop(); 

    NodeState state() const; 
    void update_state(NodeState new_state);
    
    private: 
    NodeState current_state; 
    }; 
}