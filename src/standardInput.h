#ifndef STANDARD_INPUT_H
#define STANDARD_INPUT_H

#include "inputManager.h" //include the inputManager interface

class standardInput : public inputManager{
public:
    string readInput() override;
};

#endif