#include "debugger.h"
using namespace std; 

void Debugger :: add_breakpoint(const Breakpoint &bp)
{
    breakpoints.push_back(bp); 
}

void Debugger :: inspect(const InspectionContext &ctx)
{
    for (auto &bp : breakpoints)
    {
        // evaluate condition(placeholder).. 
        if (ctx.trust_score < 0.2)
        {
            bp.triggered = true; 
        }
    }
}