#pragma once 
#include <iostream>
#include <cstdlib>

using namespace std; 

#define AIC_ASSERT_TRUE(cond) \
    if (!(cond)) { \
        cerr << "[FAIL] " << __FILE__ << ":" << __LINE__ \
                  << " Expected TRUE: " << #cond << "\n"; \
        exit(1); \
    }

#define AIC_ASSERT_FALSE(cond) \
    if ((cond)) { \
        cerr << "[FAIL] " << __FILE__ << ":" << __LINE__ \
                  << " Expected FALSE: " << #cond << "\n"; \
        exit(1); \
    }

#define AIC_ASSERT_EQ(a, b) \
    if (!((a) == (b))) { \
        cerr << "[FAIL] " << __FILE__ << ":" << __LINE__ \
                  << " Expected EQ: " << #a << " == " << #b << "\n"; \
        exit(1); \
    }