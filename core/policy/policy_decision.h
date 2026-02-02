#pragma once 

#include <string> 
using namespace std; 

namespace aic :: core :: policy 
{
    enum class PolicyDecisionType 
    {
        Allow, 
        Deny, 
        Throttle, 
        Escalate
    }; 

    struct PolicyDecision
    {
        PolicyDecisionType decision; 
        string reason; 
    }; 
}