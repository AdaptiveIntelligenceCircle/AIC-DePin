#pragma once 
#include <string> 

using namespace std; 

namespace aic :: depin :: resource 
{
    class PhysicalPresence 
    {
        public: 
        bool verify(const string &node_id, 
        const string &proof) const 
        {
            // placeholder : 
            // GPS proof / sensor / witness / challenge .. 
            return !proof.empty();
        }

        bool eligible(double trust_score) const 
        {
            return trust_score > 0.5; 
        }
    }; 
}