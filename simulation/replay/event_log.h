#pragma once 
#include <string>

#include <vector> 
using namespace std; 

struct Event
{
    int timestamp; 
    string source; 
    string description; 
}; 

class EventLog
{
    public: 
    void append(const Event&); 
    const vector<Event> &events() const; 

    private:
    vector<Event> log; 
}; 