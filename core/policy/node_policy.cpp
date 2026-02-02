#include "node_policy.h"
using namespace std;

namespace aic :: core :: policy 
{
    PolicyDecision NodePolicy :: evaluate(
        const PolicyContext &context
    ) const 
    {
        if (context.risk_level > 0.8) 
        {
            return 
            {
                PolicyDecisionType :: Throttle, 
                "Node risk level too high"
            };
        }
        return 
        {
            PolicyDecisionType :: Allow, ""
        }; 
    }
}