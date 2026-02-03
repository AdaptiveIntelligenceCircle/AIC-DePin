#pragma once 
#include "route_policy.h"
using namespace std; 

namespace aic :: network :: routing 
{
    // vi du policy mac dinh (co the thay the).. 
    class DefaultRoutePolicy : public RoutePolicy 
    {
        public: 
        RouteDecision evaluate(
            const RouteContext &ctx
        ) const override 
        {
            if (ctx.suspected_adversary)
            {
                return RouteDecision ::Deny ; 
            }
            if (ctx.trust_score < 0.3)
            {
                return RouteDecision :: Degrade; 
            }
            return RouteDecision :: Allow; 
        }
    }; 
}