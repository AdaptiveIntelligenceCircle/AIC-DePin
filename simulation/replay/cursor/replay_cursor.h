// #pragma once 

// class ReplayCursor
// {
//     public: 
//     void seek(int t); 
//     int position() const; 

//     private: 
//     int current = 0; 
// }; 

#pragma once 
#include <cstdint>

#include <iostream>
using namespace std; 

namespace aic :: simulation :: replay 
{
    struct ReplayCursor 
    {
        uint64_t event_id = 0; 
        uint64_t timestamp = 0; 

        bool operator<(const ReplayCursor &other)const 
        {
            return event_id < other.event_id;  
        }
    }; 
}