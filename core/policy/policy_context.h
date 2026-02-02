#pragma once 

#include <string> 
using namespace std;

namespace aic :: core :: policy 
{
    struct PolicyContext 
    {
        string node_id; 
        string action; 
        double risk_level; 
        double trust_score; 

        bool under_dispute; 
        bool human_override; 
    }; 
}