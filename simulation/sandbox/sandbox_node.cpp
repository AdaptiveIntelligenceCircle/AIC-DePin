#include "sandbox_node.h"
using namespace std; 

SandboxNode :: SandboxNode(int id)
: node_id(id), current_state(NodeState :: INIT){}

void SandboxNode :: tick()
{
    if(current_state == NodeState :: INIT)
    {
        current_state = NodeState :: ACTIVE; 
    }
}

void SandboxNode :: act()
{
    // behavior injected by scenario..//
}

NodeState SandboxNode :: state() const 
{
    return current_state; 
}