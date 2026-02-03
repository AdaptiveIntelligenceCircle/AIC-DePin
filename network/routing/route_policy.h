#pragma once 
#include <iostream> 

#include <string> 
using namespace std; 

// class RoutePolicy
// {
//     public: 
//     bool allow(const char *from, const char *to); 
// }; 

namespace aic :: network :: routing 
{
    struct RouteContext 
    {
        string from_node; 
        string to_node; 
        double trust_score;
        double latency; 
        bool suspected_adversary; 
    }; 

    enum class RouteDecision 
    {
        Allow, 
        Deny, 
        Degrade
    };

    class RoutePolicy 
    {
        public: 
        virtual ~RoutePolicy() = default; 

        virtual RouteDecision evaluate(
            const RouteContext &ctx
        ) const = 0; 
    }; 
}