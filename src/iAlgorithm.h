#ifndef IALGORITHM_H
#define IALGORITHM_H

#include "DataStructure.h"

class IAlgorithm {
public:
    virtual void recommend(DataStructure& dataStructure, int userId, int movieId) = 0;
    virtual ~IAlgorithm() {}
};

#endif
