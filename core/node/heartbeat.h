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
        HeartBeat(const string &node_id); 

        void emit();
        bool verify();

        void beat(); 
        double lastSeen() const; 

        bool isAlive(double timeout) const;
        double now(); 

        private: 
        string node_id_; 
        bool alive_; 
        uint64_t last_heartbeat_; 
    };
}