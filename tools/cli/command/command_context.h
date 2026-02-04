#pragma once 
#include <iostream>
using namespace std; 

#include <string> 

namespace aic :: cli
{
    struct CommandContext 
    {
        string caller_id; 
        double trust_score = 0.0; 

        bool dry_run = false; 
        bool explain = false; 

        // Pointers to systems views (read-only by default).. 
        void *node_view = nullptr; 
        void *trust_view = nullptr; 
        void *governance_view = nullptr; 
    }; 
}