#pragma once 
#include "node_state.h"

#include <iostream>
using namespace std;

class NodeLifeCycle
{
    public: 
    void evaluate();
    void degrade(); 
    void quarantine();   
};

