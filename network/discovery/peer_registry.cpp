#include "peer_registry.h"
using namespace std; 

namespace aic :: network :: discovery
{
    void PeerRegistry :: addPeer(const NodeIdentity &peer)
    {
        peers_[peer.node_id]  = peer; 
    }

    void PeerRegistry :: removePeer(const string &node_id)
    {
        peers_.erase(node_id); 
    }

    bool PeerRegistry :: hasPeer(const string &node_id) const
    {
        return peers_.count(node_id) > 0; 
    }

    vector <NodeIdentity> PeerRegistry :: listPeers() const 
    {
        vector<NodeIdentity> result; 
        for (const auto &[id, peer] : peers_)
        {
            result.push_back(peer); 
        }
        return result; 
    }

    vector<NodeIdentity> PeerRegistry :: trustedPeers() const 
    {
        vector<NodeIdentity> result; 
        for (const auto &[id, peer] : peers_)
        {
            if (peer.trusted)
            {
                result.push_back(peer); 
            }
        }
        return result; 
    }

    void PeerRegistry :: updateReputation(const string &node_id, double delta)
    {
        if (!hasPeer(node_id))
        {
            return ; 
        }

        auto &peer = peers_[node_id]; 

        peer.reputation += delta; 

        if (peer.reputation > 1.0)
        {
            peer.reputation = 1.0; 
        }
        else if (peer.reputation < 0.0)
        {
            peer.reputation = 0.0; 
        }
    }
}