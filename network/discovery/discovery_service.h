#pragma once 
#include "node_identity.h"
using namespace std; 

#include "peer_registry.h"
#include "bootstrap_strategy.h"
#include <memory>

namespace aic :: network :: discovery
{
    class DiscoveryService
    {
        public: 
        explicit DiscoveryService(
            unique_ptr<BootstrapStrategy> bootstrap
        ); 

        void start(); 

        void discoveredFromPeer(const NodeIdentity&peer); 
        void heartbeat(const string &node_id); 

        PeerRegistry &registry(); 

        private: 
        PeerRegistry registry_; 
        unique_ptr<BootstrapStrategy> bootstrap_; 
    }; 
}