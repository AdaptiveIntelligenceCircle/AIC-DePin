#pragma once 
#include <iostream> 

using namespace std; 

#include <string> 
#include <cmath> 

namespace aic :: simulation :: replay 
{
    enum class EventType 
    {
        DECISION, 
        STATE_CHANGE, 
        SYNC, 
        SLASHING, 
        OVERRIDE, 
        GOVERNANCE
    }; 

    struct Event 
    {
        uint64_t id;
        EventType type; 
        uint64_t timestamp; // node / human / system
        string origin; // serialized

        string hash; // intergrity
    }; 
}