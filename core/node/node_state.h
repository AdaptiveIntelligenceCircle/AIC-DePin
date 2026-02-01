#pragma once

namespace aic ::node
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
