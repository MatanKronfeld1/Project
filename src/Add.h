#ifndef ADD_H
#define ADD_H

#include "Icommand.h"
#include "DataFilesManager.h"
#include "originalDataManager.h"
#include "User.h"
#include "DataStructure.h"
#include <sstream>

class Add : public Icommand{
public:
    void execute(istringstream& stream, DataStructure* data, originalDataManager* dataManager) override;
    bool checkInputValidity(istringstream& stream);
};

#endif