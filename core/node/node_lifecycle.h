#pragma once
#include "node_state.h"

#include <iostream>
using namespace std;

namespace aic ::node
{
    class NodeLifeCycle
    {
    public:
        void evaluate();
        void degrade();
        void quarantine();
    };
}
