#include "App.h"
#include "Icommand.h"
#include "Recommend.h"
#include <map>
#include <string>





int main() {
    std::map <std::string, Icommand*> commands;
    
    Icommand* recommend = new Recommend();
    commands["recommend"] = recommend;
    commands["Recommend"] = recommend;

    App app(commands);
    return 0;
}