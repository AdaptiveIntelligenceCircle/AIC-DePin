#pragma once 

#include <string>
using namespace std;

struct Rule
{
    string name; 
    bool (*evaluate)(); 
}; 