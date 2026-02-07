#pragma once 
using namespace std; 

namespace aic :: sandbox 
{
    struct ScenarioConstraints 
    {
        bool allow_real_penalty = false; 
        bool allow_reputation_damage = false; 
        bool allow_governance_override = false; 

        int max_steps = 1000; 
    }; 
}