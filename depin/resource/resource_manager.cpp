#include "resource_manager.h"
using namespace std; 

namespace aic :: depin :: resource
{
    ResourceManager :: ResourceManager() = default; 

    bool ResourceManager :: request(const string &node_id, 
    ResourceType type, 
    double amount, double stake_weight, 
    double trust_score) 
    {
        auto quota = quota_model_.compute(stake_weight, trust_score, type); 

        if (!allocation_policy_.allow(node_id, type, amount, quota, usage_tracker_))
        {
            return false; 
        }

        usage_tracker_.consume(node_id, type, amount); 
        return true; 
    }
}