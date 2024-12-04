#ifndef APP_H
#define APP_H
#include <map>
#include "Icommand.h"
#include "outputManager.h"
#include "inputManager.h"
#include "DataStructure.h"
#include "originalDataManager.h"

class App {
public:
App(map <std::string, Icommand*> commands) : commands(commands) {}
void run(outputManager* outputManager, inputManager* inputManager);
private:
    map <std::string, Icommand*> commands;

};

#endif