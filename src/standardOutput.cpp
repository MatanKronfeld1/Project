/*
class that implements outputManager interface and handle
writing output to the console.
*/
#include <iostream>
#include "standardOutput.h"

using std::cout;
using std::endl;

void standardOutput::writeOutput(const string& output){
    //write output to standard output (the console)
    cout << output << endl;
}

