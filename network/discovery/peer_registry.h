#pragma once
#include <unordered_map>

#include <vector> 
#include "node_identity.h"
using namespace std; 

namespace aic :: network :: discovery
{
    class PeerRegistry
    {
        public: 
        void addPeer(const NodeIdentity &peer); 
        void removePeer(const string &node_id); 

        bool hasPeer(const string &node_id) const;
        
        vector<NodeIdentity> listPeers() const; 
        vector<NodeIdentity> trustedPeers() const; 

        void updateReputation(const string &node_id, double delta); 

        private: 
        unordered_map<string, NodeIdentity> peers_; 
    };
}