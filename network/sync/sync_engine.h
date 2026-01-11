#pragma once 
#include "state_diff.h"

using namespace std; 

class SyncEngine
{
    public:
    void push_diff(const StateDiff&); 
    void pull_diff(); 
}; 