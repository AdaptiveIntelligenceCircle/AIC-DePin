#pragma once 
#include <string> 
#include <unordered_map>
#include <chrono> 

using namespace std;

namespace aic :: depin :: slashing 
{
    struct SlashingContext
    {
        string node_id; 
        string resource_id; 
        string violation_type; 

        chrono :: system_clock :: time_point timestamp; 

        unordered_map<string, double> metrics; 
        unordered_map<string, string> metadata; 
    }; 
}