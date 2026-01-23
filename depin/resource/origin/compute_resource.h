#pragma once 
#include <string> 
using namespace std; 
#include "resource_type.h"

namespace aic :: depin :: resource
{
    class ComputeResource
    {
        public: 
        bool isValidRequest(double amount) const 
        {
            return amount > 0.0; 
        }

        double normalize(double raw_units) const 
        {
            return raw_units; // CPU cycles abstraction.
        }
    };  
}