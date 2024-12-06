#include <gtest/gtest.h>
#include <sstream>
#include <fstream>
#include "DataStructure.h"
#include "DataFilesManager.h"
#include "Add.h"
#include "User.h"
#include "Movie.h"

class AddTest : public ::testing::Test{
    protected:
    DataStructure data; //call upload?
    DataFilesManager filesManager;
    Add add;

    void SetUp() override{
        //???
    }

    void TearDown() override{
        /*
        in order to clean after each test to ensure thatdataFile.txt
        is deleted after the test
        */
       //remove(dataManager.getFilePath().c_str()); ???
        remove()
    }

    bool fileExists(){
        //std::ifstream file() ???
        return file.good();
    }
};

//test adding new user
TEST_F(AddTest, AddCompletelyNewUser){
    std::string inptStr = "1 101 102";
    std::istringstream inputStream(inputStr);
    add.execute(inputStream, &data, &filesManager);

    ASSERT_TRUE(fileExists());

}