#pragma once
#include <iostream>
using namespace std;

namespace aic :: core ::node
{
    class HeartBeat
    {
        public:
        HeartBeat() = default;
        ~HeartBeat() = default;  

        void emit();
        bool verify();

        void beat(); 
        double lastSeen() const; 

        bool isAlive(double timeout) const;
        double now(); 
    };
}