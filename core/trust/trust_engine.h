#pragma once 
#include "trust_score.h"

using namespace std; 

class TrustEngine
{
    public: 
    void observe_success(); 
    void observe_failure(); 

    TrustScore current() const; 

    private: 
    TrustScore trust; 
};  