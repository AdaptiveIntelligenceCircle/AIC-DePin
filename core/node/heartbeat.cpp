#include "heartbeat.h"
#include <chrono>

namespace aic :: core :: node 
{
    using Clock = chrono :: steady_clock;
    
    HeartBeat :: HeartBeat(const string &node_id)
    {
        node_id_ = node_id; 
        alive_ = true;
        last_heartbeat_ = now();  
    }
    void HeartBeat :: emit()
    {
        // futhur extension.
    }

    bool HeartBeat :: verify()
    {
        if (!alive_) 
        return false;
        else true;
    }

    void HeartBeat :: beat()
    {
        last_heartbeat_ = now(); 
        alive_ = true; 
    }

    double HeartBeat :: lastSeen() const 
    {
        return last_heartbeat_; 
    }

    bool HeartBeat :: isAlive(double timeout) const 
    {
        return (last_heartbeat_) <= timeout; 
    }

    double HeartBeat :: now()
    {
        return chrono :: duration_cast<chrono :: seconds>
        (
            Clock :: now().time_since_epoch()
        ).count(); 
    }
}