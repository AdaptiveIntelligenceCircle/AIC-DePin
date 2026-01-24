#pragma once 
#include <vector> 
#include <string> 

#include <iostream>
using namespace std; 

namespace aic :: depin :: slashing 
{
    struct Evidence 
    {
        string evidence_id; 
        string source; 
        string type; 

        vector<uint8_t> raw_data; 
        string summary; 
    }; 
}