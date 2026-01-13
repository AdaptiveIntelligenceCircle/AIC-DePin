#pragma once 
#include "event_log.h"

#include "replay_cursor.h"
using namespace std; 

class ReplayEngine
{
    public: 
    ReplayEngine(const EventLog&); 

    void replay_until(int timestamp);
    void step();

    private: 
    const EventLog &log; 
    ReplayCursor cursor; 
};