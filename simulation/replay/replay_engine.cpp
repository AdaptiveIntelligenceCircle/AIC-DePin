#include "replay_engine.h"

using namespace std; 

ReplayEngine :: ReplayEngine(const EventLog& l) : log(l){}

void ReplayEngine :: replay_until(int timestamp)
{
    while(cursor.position() < timestamp)
    {
        step(); 
    }
}

void ReplayEngine :: step()
{
    // apply event 
}