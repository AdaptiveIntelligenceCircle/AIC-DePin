#include "policy_engine.h"
using namespace std; 

namespace aic :: core :: policy 
{
    void PolicyEngine :: registerPolicy(
        unique_ptr<Policy> policy 
    )
    {
        policies_.push_back(move(policy)); 
    }

    PolicyDecision PolicyEngine :: evaluate(
        const PolicyContext &context
    ) const 
    {
        for (const auto &policy : policies_)
        {
            PolicyDecision decision = policy -> evaluate(context); 
            if (decision.decision != PolicyDecisionType :: Allow)
            {
                return decision; // Fail - first..
            }
        }
        return 
        {
            PolicyDecisionType :: Allow, "All policies passed"
        }; 
    }
}