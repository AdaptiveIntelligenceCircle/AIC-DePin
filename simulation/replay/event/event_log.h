// #pragma once 
// #include <string>

// #include <vector> 
// using namespace std; 

// struct Event
// {
//     int timestamp; 
//     string source; 
//     string description; 
// }; 

// class EventLog
// {
//     public: 
//     void append(const Event&); 
//     const vector<Event> &events() const; 

//     private:
//     vector<Event> log; 
// }; 

#pragma once 
#include <vector> 

#include "event.h"
using namespace std; 

namespace aic :: simulation :: replay 
{
    class EventLog 
    {
        public: 
        void append(const Event &event); 

        const vector<Event> &events() const; 
        const Event *getById(uint64_t id) const; 

        private: 
        vector<Event> events_; // append only. 
    }; 
}