#include <gtest/gtest.h>
#include "DataStructure.h"
#include "User.h"
#include "Movie.h"

// Test Constructor
TEST(DataStructureTest, Constructor) {
    DataStructure ds;
    EXPECT_EQ(ds.get_users().size(), 0); // Initial user list should be empty
}

// Test Add User
TEST(DataStructureTest, AddUser) {
    DataStructure ds;
    ds.add_User(1, {}); // Add user with no movies
    EXPECT_EQ(ds.get_users().size(), 1); // User list should have one user
    EXPECT_EQ(ds.get_users()[0].getId(), 1); // Verify user ID
}

// Test Add User with Movies
TEST(DataStructureTest, AddUserWithMovies) {
    DataStructure ds;
    Movie movie1(101);
    Movie movie2(102);

    std::unordered_set<Movie, Movie::MovieHash> movies = {movie1, movie2};
    ds.add_User(1, movies);

    EXPECT_EQ(ds.get_users().size(), 1); // Verify one user added
    EXPECT_TRUE(ds.get_users()[0].getWatchedMovies().find(movie1) != ds.get_users()[0].getWatchedMovies().end());
    EXPECT_TRUE(ds.get_users()[0].getWatchedMovies().find(movie2) != ds.get_users()[0].getWatchedMovies().end());
}

// Test Find User by ID
TEST(DataStructureTest, FindUser) {
    DataStructure ds;
    ds.add_User(1, {});
    User user = ds.find_user(1);

    EXPECT_EQ(user.getId(), 1); // Verify the user is found
}

TEST(DataStructureTest, FindUserThrowsOnInvalidId) {
    DataStructure ds;
    ds.add_User(1, {});
    EXPECT_THROW(ds.find_user(2), const char*); // Verify exception on invalid ID
}

// Test Find User Pointer
TEST(DataStructureTest, FindUserPointer) {
    DataStructure ds;
    ds.add_User(1, {});
    User* userPtr = ds.find_user_ptr(1);

    ASSERT_NE(userPtr, nullptr); // Verify the pointer is not null
    EXPECT_EQ(userPtr->getId(), 1); // Verify the user ID
}

TEST(DataStructureTest, FindUserPointerInvalidId) {
    DataStructure ds;
    User* userPtr = ds.find_user_ptr(1);

    EXPECT_EQ(userPtr, nullptr); // Verify null pointer for invalid ID
}

// Test Find Movie for User
TEST(DataStructureTest, FindMovieForUser) {
    DataStructure ds;
    Movie movie1(101);
    std::unordered_set<Movie, Movie::MovieHash> movies = {movie1};

    ds.add_User(1, movies);
    User user = ds.find_user(1);

    EXPECT_TRUE(ds.find_movie(user, movie1)); // Verify the movie is found
}

// Test Adding Duplicate User Adds Movies
TEST(DataStructureTest, AddDuplicateUserAddsMovies) {
    DataStructure ds;
    Movie movie1(101);
    Movie movie2(102);

    ds.add_User(1, {movie1});
    ds.add_User(1, {movie2}); // Add movies to the same user

    const auto& users = ds.get_users();
    EXPECT_EQ(users.size(), 1); // Still one user
    EXPECT_TRUE(users[0].getWatchedMovies().find(movie1) != users[0].getWatchedMovies().end());
    EXPECT_TRUE(users[0].getWatchedMovies().find(movie2) != users[0].getWatchedMovies().end());
}

// Test Get Users
TEST(DataStructureTest, GetUsers) {
    DataStructure ds;
    ds.add_User(1, {});
    ds.add_User(2, {});

    const auto& users = ds.get_users();
    EXPECT_EQ(users.size(), 2); // Verify two users added
    EXPECT_EQ(users[0].getId(), 1);
    EXPECT_EQ(users[1].getId(), 2);
}

// Main function to run all tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
