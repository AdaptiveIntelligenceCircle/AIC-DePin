#pragma once 

using namespace std; 

#include <iostream>
#include <string> 

class TrustScore
{
    public: 
    TrustScore(); 

    double value() const; 
    void increase(double); 
    void decrease(double); 

    private: 
    double score; 
};

