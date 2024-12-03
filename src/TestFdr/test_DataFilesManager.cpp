#include <gtest/gtest.h>
#include <fstream>
#include <sstream>
#include <vector>
#include "DataFilesManager.h"
#include "User.h"
#include "Movie.h"
#include "DataStructure.h"

// Helper function to write to a file (used for testing)
void writeFile(const std::string& filename, const std::string& content) {
    std::ofstream outFile(filename);
    outFile << content;
    outFile.close();
}

// Helper function to read from a file (used for testing)
std::string readFile(const std::string& filename) {
    std::ifstream inFile(filename);
    std::stringstream buffer;
    buffer << inFile.rdbuf();
    return buffer.str();
}

// Test suite for DataFilesManager
class DataFilesManagerTest : public ::testing::Test {
protected:
    DataFilesManager manager;
    const std::string testFilePath = "../data/dataFile.txt";

    // Set up test file before each test
    void SetUp() override {
        // Create a mock file with some initial data
        std::string initialData = "1 101 102 103\n2 104 105\n";
        writeFile(testFilePath, initialData);
    }

    // Clean up after each test
    void TearDown() override {
        std::remove(testFilePath.c_str()); // Delete the file after the test
    }
};

// Test for uploadData method
TEST_F(DataFilesManagerTest, UploadDataReadsCorrectly) {
    DataStructure* data = manager.uploadData();
    ASSERT_NE(data, nullptr);  // Ensure data is not null

    // Retrieve the vector of users
    const vector<User>& users = data->get_users();

    // Check if the data contains 2 users
    EXPECT_EQ(users.size(), 2);  // Assuming the file contains 2 users

    // Verify User 1 and its movies
    User user1 = data->find_user(1);  // Assuming user ID 1 exists in the data
    EXPECT_EQ(user1.getId(), 1);
    const std::unordered_set<Movie>& user1Movies = user1.getWatchedMovies();
    EXPECT_EQ(user1Movies.size(), 3);  // User 1 has 3 movies (as in the example)

    // Verify User 2 and its movies
    User user2 = data->find_user(2);  // Assuming user ID 2 exists in the data
    EXPECT_EQ(user2.getId(), 2);
    const std::unordered_set<Movie>& user2Movies = user2.getWatchedMovies();
    EXPECT_EQ(user2Movies.size(), 2);  // User 2 has 2 movies (as in the example)

    delete data; // Cleanup
}

// Test for addMoviesToUser method
TEST_F(DataFilesManagerTest, AddMoviesToUserAppendsCorrectly) {
    User user(1);
    std::vector<Movie> moviesToAdd = { Movie(106), Movie(107) };

    // Before adding movies, check file content
    std::string contentBefore = readFile(testFilePath);
    manager.addMoviesToUser(user, moviesToAdd);

    // After adding movies, verify the updated content
    std::string contentAfter = readFile(testFilePath);
    EXPECT_NE(contentBefore, contentAfter);  // Content should change

    // Check if the new movies are added to the user line in the file
    EXPECT_TRUE(contentAfter.find("1 101 102 103 106 107") != std::string::npos);
}

// Test for addRecordToData method
TEST_F(DataFilesManagerTest, AddRecordToDataAddsCorrectly) {
    User newUser(3);
    std::vector<Movie> moviesToAdd = { Movie(108), Movie(109) };

    // Add a new record to the data file
    manager.addRecordToData(newUser, moviesToAdd);

    // Verify that the new user and movies are added to the file
    std::string contentAfter = readFile(testFilePath);
    EXPECT_TRUE(contentAfter.find("3 108 109") != std::string::npos);
}


int main (int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}