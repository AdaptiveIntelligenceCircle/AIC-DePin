#pragma once 
#include "policy.h"
using namespace std; 

namespace aic :: core :: policy 
{
    class SlashingPolicy : public Policy
    {
        public: 
        PolicyDecision evaluate(
            const PolicyContext &context
        ) const override; 
    }; 
}