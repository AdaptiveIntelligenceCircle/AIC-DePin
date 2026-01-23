#pragma once 
#include <unordered_map>
#include "resource_type.h"
#include <map> 
using namespace std; 

namespace aic :: depin :: resource
{
    class UsageTracker
    {
        public:
        void consume(const string &node_id, ResourceType type, double amount); 
        double usageOf(const string &node_id, ResourceType type ) const; 

        void resetEpoch();

        private: 
        unordered_map<string, unordered_map<ResourceType, double>> usage_;
    }; 
}