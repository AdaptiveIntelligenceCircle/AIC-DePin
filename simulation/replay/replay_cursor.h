#pragma once 

class ReplayCursor
{
    public: 
    void seek(int t); 
    int position() const; 

    private: 
    int current = 0; 
}; 