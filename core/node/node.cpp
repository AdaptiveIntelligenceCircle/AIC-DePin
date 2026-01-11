#include "node.h"

Node :: Node() : current_state(NodeState :: INIT){}

void Node :: start()
{
    current_state = NodeState :: ACTIVE; 
}

void Node :: stop()
{
    current_state = NodeState :: EXPELLED; 
}

NodeState Node :: state() const 
{
    return current_state; 
}

void Node :: update_state(NodeState new_state)
{
    current_state = new_state; 
}