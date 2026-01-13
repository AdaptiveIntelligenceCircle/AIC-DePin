#pragma once 
class ReplayPolicy
{
    public: 
    bool allow_full_replay() const; 
    bool allow_partial_replay() const; 
};