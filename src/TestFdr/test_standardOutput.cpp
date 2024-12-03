#include <gtest/gtest.h>
#include <sstream>
#include "standardOutput.h"

using std::string;

//global output stream for capturing the output
std::ostringstream g_outputStream;

//function to redirect std::cout to the string stream
void redirectStdOut(){
    //redirect std::cout to the string stream
    std::cout.rdbuf(g_outputStream.rdbuf());
}

//test for writing simple output
TEST(WriteSimpleOutput, HandlesCorrectly){
    redirectStdOut();
    standardOutput output;
    output.writeOutput("Hello, world!");
    EXPECT_EQ(g_outputStream.str(),"Hello, world!");
}

//test for writing empty output
TEST(WriteEmptyOutput, HandlesEmptyOutput){
    redirectStdOut();
    standardOutput output;
    output.writeOutput("");
    EXPECT_EQ(g_outputStream.str(),"");
}

//test for writing special output
TEST(WriteSpecialOutput, HandlesSpecialOutput){
    redirectStdOut();
    standardOutput output;
    output.writeOutput("!@#$%");
    EXPECT_EQ(g_outputStream.str(),"!@#$%");
}

//test for writing output with a new line
TEST(WriteNewLineOutput, HandlesNewLineOutput){
    redirectStdOut();
    standardOutput output;
    output.writeOutput("Hello \nWorld");
    EXPECT_EQ(g_outputStream.str(),"Hello \nWorld");
}

int main (int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

