#include <gtest/gtest.h>
#include <sstream>
#include "standardInput.h"

using std::string;

void simulateInput(const string& input){
    //create an input stream from the string
    std::istringstream input_stream(input);
    //redirect std::cin to use the input stream
    std::cin.rdbuf(input_stream.rdbuf());
}

//test for reading simple input
TEST(ReadSimpleInput, HandlesCorrectly){
    simulateInput("Hello world!");
    standardInput input;
    string result = input.readInput();

    EXPECT_EQ(result, "Hello world!");
}

//test for reading empty input
TEST(ReadEmptyInput, HandlesEmptyInput){
    simulateInput("");
    standardInput input;
    string result = input.readInput();
    EXPECT_EQ(result, "");
}

//test for reading spacial characters
TEST(ReadSpacialInput, HandlesSpacialInput){
    simulateInput("!@#$%^&");
    standardInput input;
    string result = input.readInput();
    EXPECT_EQ(result, "!@#$%^&");
}

//test for reading spaces and new line
TEST(ReadInputWithSpacesAndNewLine, HandlesInputWithSpacesAndNewLine){
    simulateInput("Hello \nworld");
    standardInput input;
    string result = input.readInput();
    EXPECT_EQ(result, "Hello");
}

int main (int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}