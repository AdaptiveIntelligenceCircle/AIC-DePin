#include "router.h"
#include <iostream>

using namespace std; 

namespace aic :: network :: routing 
{
    Router :: Router(
        unique_ptr<RoutePolicy> policy
    ) : policy_(move(policy)){}

    RoutingTable &Router :: routingTable()
    {
        return table_; 
    }

    bool Router :: routeMessage(
        const string &from, 
        const string &to
    )
    {
        if (!table_.hasRoute(to)){
            cerr <<"No Route to destination\n"; 
            return false; 
        }

        RouteEntry entry = table_.getRoute(to);
        
        RouteContext ctx 
        {
            from, 
            to, 
            entry.trust_score, 
            entry.avg_latency, 
            false // adversary flag (tam).. 
        };  

        RouteDecision decision = policy_->evaluate(ctx);

    if (decision == RouteDecision::Deny) {
        cerr << "Routing denied by policy\n";
        return false;
    }

    if (decision == RouteDecision::Degrade) {
        cerr << "Routing degraded (slow path)\n";
    }

    // Thực tế: gửi message qua entry.next_hop
        cout << "Routing message via "
              << entry.next_hop << "\n";

    return true;
    }

}