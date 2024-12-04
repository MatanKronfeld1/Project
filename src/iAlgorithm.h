#ifndef IALGORITHM_H
#define IALGORITHM_H
#include <vector>

using namespace std;

#include "DataStructure.h"

class IAlgorithm {
public:
    virtual vector <int> recommend(DataStructure& dataStructure, int userId, int movieId) = 0;
    virtual ~IAlgorithm() {}
};

#endif
