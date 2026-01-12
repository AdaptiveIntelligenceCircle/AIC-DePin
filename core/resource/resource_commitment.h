#pragma once 
#include "resource.h"

using namespace std; 

class ResourceCommitment
{
    public: 
    bool commit(const Resource&); 
    void release(const Resource&); 
}; 