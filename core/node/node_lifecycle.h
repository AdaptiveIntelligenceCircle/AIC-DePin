#pragma once
#include "node_state.h"

#include <iostream>
using namespace std;

namespace aic :: core :: node
{
    class NodeLifeCycle
    {
        public:

        NodeLifeCycle() = default; 
        ~NodeLifeCycle() = default; 
        NodeLifeCycle(const string &node_id); 

        void evaluate();
        void degrade();
        void quarantine();

        NodeState state() const; 
        void transition(NodeState state); 
        bool invalidTransition(NodeState from, NodeState to) const; 
    };
}
