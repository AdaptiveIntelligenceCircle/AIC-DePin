#pragma once 
using namespace std; 

class RoutePolicy
{
    public: 
    bool allow(const char *from, const char *to); 
}; 