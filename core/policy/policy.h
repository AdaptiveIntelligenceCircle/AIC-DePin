#pragma once 
#include <vector> 
#include "rule.h"

using namespace std;

class Policy
{
    public: 
    void add_rule(const Rule&); 
    bool evaluate_all() const; 

    private: 
    vector<Rule> rules; 
}; 