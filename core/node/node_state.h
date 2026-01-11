#pragma once 

enum class NodeState
{
    INIT, 
    ACTIVE, 
    DEGRADED, 
    QUARANTINED, 
    EXPELLED
}; 