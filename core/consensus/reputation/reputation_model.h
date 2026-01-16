#pragma once 
#include <string> 

using namespace std; 

class ReputationModel
{
    public: 
    void update(double behavior_score); 
    double value() const; 

    private: 
    double reputation_ = 0.5; // neutral start.
}; 