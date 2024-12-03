#ifndef ALGORITHM1_H
#define ALGORITHM1_H

#include "iAlgorithm.h"
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "Movie.h"
#include "User.h"
#include "DataStructure.h"

class Algorithm1 : public IAlgorithm {
public:
    // Method to recommend movies based on mutual movies with the target user
    void recommend(DataStructure& dataStructure, int userId, int movieId) override;
};

#endif
