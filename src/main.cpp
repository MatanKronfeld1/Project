#include "App.h"
#include "Icommand.h"
#include "Recommend.h"
#include "standardInput.h"
#include "standardOutput.h"
#include "Add.h"
#include <map>
#include <string>





int main() {
    std::map <std::string, Icommand*> commands;
    inputManager* si = new standardInput();
    outputManager* so = new standardOutput();
    Icommand* recommend = new Recommend();
    Icommand* add = new Add();
    commands["recommend"] = recommend;
    //commands["help"] = new Help();
    commands["add"] = add;
    App app(commands);
    app.run(so, si);
    return 0;
}