#pragma once 
#include "node_identity.h"
using namespace std; 

class DiscoveryService
{
    public: 
    void announce(); 
    void listen(); 
    void probe_node(const NodeIdentity& candidate);  
}; 