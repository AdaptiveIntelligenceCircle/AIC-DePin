// #pragma once 
// #include "event_log.h"

// #include "replay_cursor.h"
// using namespace std; 

// class ReplayEngine
// {
//     public: 
//     ReplayEngine(const EventLog&); 

//     void replay_until(int timestamp);
//     void step();

//     private: 
//     const EventLog &log; 
//     ReplayCursor cursor; 
// };

#pragma once
#include "../event/event_log.h"
#include "../analysis/replay_result.h"
#include "replay_session.h"

namespace aic::simulation::replay {

class ReplayEngine {
public:
    ReplayResult run(
        const EventLog& log,
        const ReplaySession& session
    );
};

}
