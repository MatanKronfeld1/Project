#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
#include "Recommend.h"
#include "App.h"
#include "standardInput.h"
#include "standardOutput.h"
#include "DataStructure.h"
#include "originalDataManager.h"
#include "DataFilesManager.h"
#include "Add.h"

using namespace std;



void App::run(outputManager* outputManager, inputManager* inputManager) {
    originalDataManager* dataManager = new DataFilesManager();
    DataStructure* dataStructure = dataManager->uploadData();
    while(true){
        try{
            string input = inputManager->readInput();
            istringstream stream(input);
            string command;
            stream >> command;

            //transform(command.begin(), command.end(), command.begin(), ::tolower);
            if(input.find('\t') != string::npos) continue; //skip if input contain tabs
            if(commands.count(command)==0) continue; //skip invalid commands
            string args;
            getline(stream, args);
            istringstream argsStream(args);
            commands[command] -> execute(argsStream, dataStructure, dataManager);
        }
        catch ( ... ) {continue;}
    }
}