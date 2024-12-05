#ifndef Icommand_H
#define Icommand_H
#include <sstream>
#include "DataStructure.h"
#include "originalDataManager.h"

using namespace std;
class Icommand {
public:
    virtual void execute(istringstream& stream, DataStructure* data, originalDataManager* dataManager) = 0;
    virtual ~Icommand() {}
};
#endif