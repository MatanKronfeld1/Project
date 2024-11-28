/*
class that implements inputManager interface and handle
reading input from the console.
*/
#include <iostream>
#include <string>
#include "standardInput.h"

using std::string;
using std::cin;
using std::getline;

string standardInput::readInput(){
    string input;
    getline(cin, input);
    return input;
    //TO DO: enable reading of many line?

}