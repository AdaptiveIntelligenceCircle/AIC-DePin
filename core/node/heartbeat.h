#pragma once

using namespace std;

namespace aic ::node
{
    class HeartBeat
    {
    public:
        void emit();
        bool verify();
    };
}