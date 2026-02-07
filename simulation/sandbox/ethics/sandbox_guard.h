#pragma once 

#include <string> 
using namespace std; 

#include <iostream>
#include "../core/sandbox_context.h"

namespace aic :: sandbox 
{
    class SandboxGuard 
    {
        public: 
        bool validate(const SandboxContext &ctx) const; 
    }; 
}
