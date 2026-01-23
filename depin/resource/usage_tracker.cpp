#include "usage_tracker.h"
#include <iostream>
using namespace std;

namespace aic :: depin :: resource
{
    void UsageTracker :: consume(const string &node_id, ResourceType type, double amount)
    {
        usage_[node_id][type] += amount; 
    }

    double UsageTracker :: usageOf(const string &node_id, ResourceType type) const 
    {
        auto it = usage_.find(node_id); 
        if (it == usage_.end())
        return 0.0; 

        auto jt = it -> second.find(type); 
        if (jt== it -> second.end()) return 0.0; 

        return jt -> second; 
    }

    void UsageTracker :: resetEpoch()
    {
        usage_.clear();
    }
}