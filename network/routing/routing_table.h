#pragma once 
#include <vector> 

#include <string> 
using namespace std; 

class RoutingTable
{
    public: 
    void add_route(const string &node_id);
    vector<string> get_routes() const;  
}; 