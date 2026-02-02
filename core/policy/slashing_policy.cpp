// slashing_policy.cpp
#include "slashing_policy.h"

namespace aic::core::policy 
{

PolicyDecision SlashingPolicy::evaluate(
    const PolicyContext& ctx
) const 
{
    if (ctx.human_override) 
    {
        return 
        { 
            PolicyDecisionType::Deny,
            "Human override blocks slashing" 
        };
    }
    return 
    { 
        PolicyDecisionType::Allow, "" 
    };
}

}
