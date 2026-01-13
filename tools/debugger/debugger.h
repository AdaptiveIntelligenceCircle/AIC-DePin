#pragma once 
#include <vector> 

#include "breakpoint.h"
#include "inspection_context.h"

using namespace std; 

class Debugger
{
    public: 
    void add_breakpoint(const Breakpoint&); 
    void inspect(const InspectionContext&); 

    private: 
    vector<Breakpoint> breakpoints; 
};  