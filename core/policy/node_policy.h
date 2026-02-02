#pragma once 
#include "policy.h"

using namespace std; 

namespace aic :: core :: policy 
{
    class NodePolicy : public Policy 
    {
        public: 
        PolicyDecision evaluate(
            const PolicyContext &context
        ) const override; 
    };
}