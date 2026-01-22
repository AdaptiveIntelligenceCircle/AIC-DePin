#pragma once

#include <vector>
#include "node_identity.h"

using namespace std;

namespace aic ::network ::discovery
{
    class BootstrapStrategy
    {
    public:
        virtual ~BootstrapStrategy() = default;

        virtual vector<NodeIdentity> initialPeers() = 0;
    };

    class StaticBootstrap : public BootstrapStrategy
    {
    public:
        explicit StaticBootstrap(vector<NodeIdentity> seeds);

        vector<NodeIdentity> initialPeers() override;

    private:
        vector<NodeIdentity> seeds_;
    };
}