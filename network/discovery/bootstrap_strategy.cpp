#include "bootstrap_strategy.h"

using namespace std; 

namespace aic :: network :: discovery
{
    StaticBootstrap :: StaticBootstrap(
        vector<NodeIdentity> seeds 
    )
    {
        seeds_ = move(seeds); 
    }

    vector<NodeIdentity> StaticBootstrap :: initialPeers()
    {
        return seeds_; 
    }
}