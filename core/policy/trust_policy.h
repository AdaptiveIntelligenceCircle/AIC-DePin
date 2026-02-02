#pragma once 
#include "policy.h"

namespace aic :: core :: policy 
{
    class TrustPolicy : public Policy 
    {
        public: 
        PolicyDecision evaluate(
            const PolicyContext &context 
        ) const override; 
    }; 
}