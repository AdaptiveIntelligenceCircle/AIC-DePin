#pragma once
#include <vector>
#include <string>

namespace aic::simulation::replay {

struct ReplayResult {
    bool success = false;

    std::vector<std::string> decisions;
    std::vector<std::string> violations;

    std::string summary;
};

}
