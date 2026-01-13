#pragma once 
#include <string> 
using namespace std ; 

struct Breakpoint
{
    string condition; // e.g. trust < 0.2 
    bool triggered = false; 
}; 