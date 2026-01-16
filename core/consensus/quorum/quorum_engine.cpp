#include "quorum_engine.h"
#include <iostream>
using namespace std; 

namespace aic :: consensus
{
    bool QuorumEngine :: evaluate(
        const QuorumContext &ctx, 
        const vector<QuorumSignal> &signals 
    ) const 
    {
        double total_weight = 0.0; 
        double approval_weight  = 0.0; 

        for (const auto &s : signals)
        {
            total_weight += s.trust_score; 
            if (s.approve)
            {
                approval_weight += s.trust_score; 
            }
        }

        if (total_weight == 0.0) return false; 

        double approval_ratio = approval_weight / total_weight;
        
        // dynamic quorum threshold.. 
        double threshold = 
        0.5 + (ctx.risk_level *0.3) + 
        ((1.0 - ctx.network_stability) *0.2); 

        return approval_ratio >= threshold; 
    }
}