#ifndef HELP_H
#define HELP_H
#include "Icommand.h"
#include "DataStructure.h"
#include "originalDataManager.h"

using namespace std;


class Help : public Icommand {
public:
    // Method to recommend movies based on mutual movies with the target user
    void execute(istringstream& stream, DataStructure* data, originalDataManager* dataManager) override;
};



#endif


