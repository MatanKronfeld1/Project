#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <string>
using std::string;

/*
an abstract class that is used as interface to handle
reading input from several types of resources.
*/

class inputManager{
public:
    virtual string readInput()=0;
    //add a virtual destructore?
};
#endif