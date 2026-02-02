#pragma once 
#include <string>
#include <algorithm>

#include "policy.h"
using namespace std; 

namespace aic :: core :: policy 
{
    class ResourcePolicy : public Policy 
    {
        public: 
        PolicyDecision evaluate(
            const PolicyContext &context
        ) const override ; 
    }; 
}