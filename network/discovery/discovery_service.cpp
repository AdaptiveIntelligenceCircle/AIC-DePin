#include "discovery_service.h"
#include <iostream>

using namespace std; 

namespace aic :: network :: discovery
{
    DiscoveryService :: DiscoveryService(
        unique_ptr<BootstrapStrategy> bootstrap
    )
    {
        bootstrap_ = move(bootstrap); 
    }

    void DiscoveryService :: start()
    {
        auto peers = bootstrap_ ->initialPeers() ; 

        for (const auto &peer : peers)
        {
            registry_.addPeer(peer); 
            cout << "[Discovery] - bootstrapped peer:"
            << peer.node_id << endl; 
        }
    }

    void DiscoveryService :: discoveredFromPeer(
        const NodeIdentity &peer
    )
    {
        if (!registry_.hasPeer(peer.node_id))
        {
            registry_.addPeer(peer); 
        }
    }

    void DiscoveryService :: heartbeat( const string &node_id)
    {
        if (!registry_.hasPeer(node_id))
        {
            return; 
        }

        registry_.updateReputation(node_id, 0.1); 
    }

    PeerRegistry &DiscoveryService :: registry()
    {
        return registry_; 
    }
}