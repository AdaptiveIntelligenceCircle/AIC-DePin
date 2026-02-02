// trust_policy.cpp
#include "trust_policy.h"

namespace aic::core::policy 
{

PolicyDecision TrustPolicy::evaluate
(
    const PolicyContext& ctx
) const 
{
    if (ctx.under_dispute) 
    {
        return 
        { 
            PolicyDecisionType::Escalate,
            "Trust evaluation under dispute" 
        };
    }
    return 
    { 
        PolicyDecisionType::Allow, "" 
    };
}

}
