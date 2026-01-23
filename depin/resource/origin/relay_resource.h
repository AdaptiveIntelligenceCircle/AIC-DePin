#pragma once 
#include <string>
using namespace std; 

namespace aic :: depin :: resource 
{
    class RelayResource 
    {
        public: 
        bool canRelay(double trust_score, double stake_weight) const 
        {
            return trust_score > 0.6 and stake_weight > 1.0; 
        }

        double relayCost(double packets) const 
        {
            return packets *1.2; // replay expensive hon send.. 
        }
    }; 
}