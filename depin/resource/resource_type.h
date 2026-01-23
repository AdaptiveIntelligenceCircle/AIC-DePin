#pragma once 
#include <string> 

using namespace std; 

namespace aic :: depin :: resource
{
    enum class ResourceType 
    {
        Compute, 
        Storage, 
        Bandwidth, 
        TaskPriority, 
        GossipVisibility
    };
    
    inline string toString(ResourceType type )
    {
        switch(type)
        {
            case ResourceType :: Compute: return "compute"; 
            case ResourceType :: Storage: return "Storage"; 
            case ResourceType :: Bandwidth: return "Banwidth";
            case ResourceType :: TaskPriority: return "TaskPriority";
            case ResourceType :: GossipVisibility: return "GossipVisibility";    
            default : return "Unknown";
        }
    }
}