#pragma once 
using namespace std; 

namespace aic :: consensus
{
    class InfluenceWeight
    {
        public:
        static double apply(double trust, double reputation); 
    }; 
}