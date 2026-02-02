#pragma once 

#include <iostream> 
using namespace std; 

#include "policy_decision.h"
#include "policy_context.h"

namespace aic :: core :: policy 
{
    class Policy
    {
        public: 
        virtual ~Policy() = default;

        virtual PolicyDecision evaluate(
            const PolicyContext &context 
        ) const = 0;
    };
}

