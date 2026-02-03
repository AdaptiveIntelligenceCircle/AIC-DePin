// #pragma once 
// #include <vector> 

// #include <string> 
// using namespace std; 

// class RoutingTable
// {
//     public: 
//     void add_route(const string &node_id);
//     vector<string> get_routes() const;  
// }; 

#pragma once 
#include <iostream>

#include <unordered_map>
#include <vector> 

#include <string>
using namespace std; 

namespace aic :: network :: routing 
{
    struct RouteEntry 
    {
        string next_hop; 
        double trust_score; 
        double avg_latency;
    }; 

    class RoutingTable 
    {
        public: 
        void updatePolicy(
            const string &destination, 
            const RouteEntry &entry
        ); 

        bool hasRoute(const string &destination) const; 

        RouteEntry getRoute(
            const string &destination 
        ) const ; 

        vector<string> knownDestinations() const ; 
        private: 
        unordered_map<string, RouteEntry> table_; 
    }; 
}