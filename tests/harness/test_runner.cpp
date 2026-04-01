#include "test_runner.h"
#include <iostream>
using namespace std;

namespace aic :: tests 
{
    void TestRunner :: add(const string &name, function<void()> fn){
        tests_.push_back({name, move(fn)}); 
    }

    int TestRunner :: runAll()
    {
        cout << "Running" << tests_.size() << "test...." << endl;  

        for (auto &t : tests_)
        {
            cout << "[TEST]" << t.name << endl; 
            t.fn(); 
            cout << "[PASS]" << t.name << endl; 
        }
        cout <<"All tests passed" << endl; 
        return 0; 
    }
}