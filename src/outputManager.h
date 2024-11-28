#ifndef OUTPUT_MANAGER_H
#define OUTPUT_MANAGER_H

#include <string>
using std::string;

/*
an abstract class that is used as interface to handle
writing output to several types of resources.
*/

class outputManager{
public:
    virtual void writeOutput(const string& output)=0;
    //add a virtual destructore?
};

#endif