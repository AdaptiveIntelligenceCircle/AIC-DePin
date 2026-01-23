#pragma once 
#include <string> 
#include <functional> 

#include "resource_type.h"
#include "quota_model.h"

#include "allocation_policy.h"
#include "usage_tracker.h"
using namespace std; 

namespace aic :: depin :: resource
{
    class ResourceManager
    {
        public: 
        ResourceManager(); 
        
        bool request(const string &node_id, 
        ResourceType type, 
        double amount, 
        double stake_weight, 
        double trust_score); 

        private: 
        QuotaModel quota_model_; 
        AllocationPolicy allocation_policy_; 
        UsageTracker usage_tracker_;
    }; 
}