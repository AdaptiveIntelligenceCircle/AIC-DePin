#pragma once 
#include <iostream>

#include <string> 
#include <vector>

using namespace std; 

namespace aic :: consensus :: quorum 
{
    /*
        context passed to quorum policy.. 
        khong chi la so luong node - ma la boi canh quyet dinh..
    */
    struct QuorumContext
    {
        string topic;  // "slashing", "task_validation"
        vector<string> voters; // "node_ids tham gia".. 
        double average_trust; // trust trung binh
        double risk_level;
    }; 

    /*
        Abstract quorum policy.. 
        Quyet dinh :quorum nay co hop le hay khong?
    */

    class QuorumPolicy 
    {
        public: 
        virtual ~QuorumPolicy() = default;

        // Return true neu quorom hop le de ra quyet dinh.. 

        virtual bool isQuorumSatisfied(
            const QuorumContext &context, 
            size_t agree_count
        ) const = 0; 
    };  
}