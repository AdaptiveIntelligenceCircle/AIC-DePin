#pragma once 
#include "routing_table.h"
using namespace std; 

#include <iostream>
#include <string> 

#include <stdexcept>

namespace aic :: network :: routing 
{
    void RoutingTable :: updatePolicy(
        const string &dest, 
        const RouteEntry &entry
    )
    {
        table_[dest] = entry; 
    }

    bool RoutingTable :: hasRoute(
        const string &dest
    ) const 
    {
        return table_.find(dest) != table_.end(); 
    }

    RouteEntry RoutingTable :: getRoute(
        const string &dest
    ) const 
    {
        auto it = table_.find(dest); 
        if (it == table_.end())
        {
            throw runtime_error("Route not found"); 
        }
        return it -> second; 
    }

    vector<string> RoutingTable :: knownDestinations() const 
    {
        vector<string> result; 
        for (const auto &[k, _] : table_)
        {
            result.push_back(k); 
        }
        return result; 
    }
}