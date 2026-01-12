#pragma once 
#include "../../core/node/node_state.h"
using namespace std; 

class SandboxNode
{
    public: 

    SandboxNode(int id);
    void tick(); 
    void act();

    NodeState state() const; 

    private: 
    int node_id; 
    NodeState current_state;
}; 
