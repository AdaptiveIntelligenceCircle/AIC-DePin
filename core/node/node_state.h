#pragma once

namespace aic :: core ::node
{
    enum class NodeState
    {
        INIT,
        ACTIVE,
        DEGRADED,
        QUARANTINED,
        EXPELLED
    };
}
