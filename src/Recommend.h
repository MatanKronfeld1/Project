#ifndef RECOMEND_H
#define RECOMEND_H
#include "Icommand.h"
#include "DataStructure.h"

using namespace std;


class Recommend : public Icommand {
public:
    // Method to recommend movies based on mutual movies with the target user
    void execute(istringstream& stream, DataStructure* data) override;
};



#endif // RECOMEND_H


