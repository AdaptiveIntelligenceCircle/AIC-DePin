#pragma once 
#include <memory>

#include <vector> 
#include "policy.h"

namespace aic :: core:: policy 
{
    class PolicyEngine 
    {
        public: 
        void registerPolicy(unique_ptr<Policy> policy); 

        PolicyDecision evaluate(
            const PolicyContext &context
        ) const; 

        private: 
        vector<unique_ptr<Policy>> policies_; 
    }; 
}   