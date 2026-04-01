#pragma once 
#include <vector> 

#include <functional>
#include <string> 
using namespace std; 

namespace aic :: tests 
{
    struct TestCase 
    {
        string name; 
        function<void()> fn; 
    }; 

    class TestRunner 
    {
        public: 
        void add(const string &name, function<void()> fn); 
        int runAll(); 

        private: 
        vector<TestCase> tests_; 
    };
}