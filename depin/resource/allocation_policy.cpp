#include "allocation_policy.h"
using namespace std; 

namespace aic :: depin :: resource 
{
    bool AllocationPolicy :: allow(const string &node_id, 
    ResourceType type, 
    double requested,
    const Quota &quota, 
    const UsageTracker &tracker
    ) const
    {
        double used = tracker.usageOf(node_id, type); 
        if (used + requested <= quota.max)
        {
            return true; 
        }
        
        if (used + requested <= quota.max + quota.burst) return true; 

        else 
        return false; 
    }
}