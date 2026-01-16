#pragma once 
#include <string> 

using namespace std; 

namespace aic :: consensus
{
    struct Task
    {
        string id; 
        double critically; // 0.0 -> 1.0
    }; 
}