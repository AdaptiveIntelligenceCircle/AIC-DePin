// #pragma once 
// #include <string> 

// using namespace std; 

// struct StateDiff
// {
//     string key; 
//     string delta; 
// }; 

#pragma once 
#include <iostream> 

using namespace std; 

#include <unordered_map>
#include <vector> 

namespace aic :: network :: sync 
{
    enum class DiffType 
    {
        ADD, 
        UPDATE, 
        REMOVE
    }; 

    struct StateChange 
    {
        string key; 
        string old_value; 
        string new_value; 
        DiffType type; 
    }; 

    class StateDiff 
    {
        public: 
        void addChange(const StateChange &change); 
        const vector<StateChange> &changes() const; 

        bool empty() const; 
        size_t size() const; 

        private: 
        vector<StateChange> m_changes;
    }; 
} // namespace aic :: network :: type.