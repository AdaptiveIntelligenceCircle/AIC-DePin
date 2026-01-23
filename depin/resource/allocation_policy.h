#pragma once 

#include <iostream>
#include <string> 

#include "quota_model.h"
#include "usage_tracker.h"

using namespace std; 

namespace aic :: depin :: resource
{
    class AllocationPolicy
    {
        public: 
        bool allow(const string &node_id, 
        ResourceType type, 
        double requested,
        const Quota &quota, 
        const UsageTracker &tracker
        ) const; 
    }; 
}