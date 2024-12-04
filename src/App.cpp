#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
#include "App.h"
#include "standardInput.h"
#include "standardOutput.h"
#include "DataStructure.h"
#include "originalDataManager.h"
#include "DataFilesManager.h"

using namespace std;




void App::run(outputManager* outputManager, inputManager* inputManager) {
    originalDataManager* dataManager = new DataFilesManager();
    DataStructure* dataStructure = dataManager->uploadData();
    vector <User> users = dataStructure->get_users();

    // Step 5: Check if the data was loaded successfully (print some data to verify)
    if (users.size() == 0) {
        outputManager->writeOutput("No data loaded");
    } else {
        outputManager->writeOutput("Data loaded successfully");
    }

    /*
   while (true) {
        string input = inputManager->readInput();
        istringstream stream(input);
        string command;
        stream >> command;
        try{
            transform(command.begin(), command.end(), command.begin(), ::tolower);
        } catch ( ... ) { goto readInputAgain; }
        try {
            commands[command]->execute(stream, data);
        } catch ( ... ) {}
    readInputAgain:;
   }
   */
}