// #pragma once 
// #include "../protocol/message.h"

// using namespace std; 

// class Router
// {
//     public: 
//     void forward(const Message&);
// }; 

#pragma once 
#include <iostream> 
#include <memory>

#include "routing_table.h"
#include "route_policy.h"

using namespace std; 

namespace aic :: network :: routing 
{
    class Router 
    {
        public: 
        Router(unique_ptr<RoutePolicy> policy); 

        bool routeMessage(
            const string &from , 
            const string &to
        ); 

        RoutingTable& routingTable(); 

        private: 
        unique_ptr<RoutePolicy> policy_; 
        RoutingTable table_; 
    }; 
}

