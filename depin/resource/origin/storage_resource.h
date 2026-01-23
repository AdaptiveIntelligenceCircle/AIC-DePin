#include <iostream> 
using namespace std; 
#include <unordered_map>
namespace aic :: depin :: resource 
{
    class StorageResource
    {
        public: 
        bool allocate(const string &node_id, double amount); 
        void release(const string &node_id, double amount); 

        double usedBy(const string &node_id) const; 

        private: 
        unordered_map<string, double> allocations_; 
    }; 
}