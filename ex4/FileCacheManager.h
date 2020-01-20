//
// Created by amitnir29 on 17/01/2020.
//

#ifndef EX4_FILECACHEMANAGER_H
#define EX4_FILECACHEMANAGER_H

#include "interfaces.h"
using namespace problem_solving;

class FileCacheManager : public CacheManager {
public:
    bool hasSolution(Solution s) override;

    Solution getSolution(Problem p) override;

    int setSolution(Problem p, Solution s) override;
};


#endif //EX4_FILECACHEMANAGER_H
