#include "storage_resource.h"
using namespace std; 

namespace aic :: depin :: resource 
{
    bool StorageResource :: allocate(const string &node_id, double amount)
    {
        if (amount <= 0.0) return false;
        allocations_[node_id] += amount; 
        return true;  
    }

    void StorageResource :: release(const string &node_id, double amount)
    {
        allocations_[node_id] -= amount; 
        if (allocations_[node_id] < 0.0)
        {
            allocations_[node_id] = 0.0; 
        }
    }

    double StorageResource :: usedBy(const string &node_id) const 
    {
        auto it = allocations_.find(node_id); 
        return it == allocations_.end() ? 0.0 : it -> second; 
    }
}