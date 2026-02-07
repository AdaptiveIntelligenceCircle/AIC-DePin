#pragma once 
#include <vector> 

#include "sandbox_node.h"
#include "scenario.h"

using namespace std; 

class SandboxRunner
{
    public: 
    void load_scenario(Scenario*);
    void add_node(const SandboxNode&);  

    void run(int ticks); 
 
    vector<SandboxNode> nodes; 
    Scenario *scenario = nullptr; 
}; 

