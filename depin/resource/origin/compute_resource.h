#pragma once 
#include <string> 
using namespace std; 

namespace aic :: depin :: resource
{
    enum class ComputeResource 
    {
        Compute, 
        Storage, 
        Banwidth, 
        TaskPriority, 
        GossipVisibility
    };
    
    inline string toString(ComputeResource type )
    {
        switch(type)
        {
            case ComputeResource :: Compute: return "compute"; 
            case ComputeResource :: Storage: return "Storage"; 
            case ComputeResource :: Banwidth: return "Banwidth";
            case ComputeResource :: TaskPriority: return "TaskPriority";
            case ComputeResource :: GossipVisibility: return "GossipVisibility";    
            default : return "Unknown";
        }
    }
}