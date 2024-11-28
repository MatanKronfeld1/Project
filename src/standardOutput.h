#ifndef STANDARD_OUTPUT_H
#define STANDARD_OUTPUT_H

#include "outputManager.h" //include the outputManager interface

class standardOutput : public outputManager{
public:
    void writeOutput(const string& output) override;
};

#endif