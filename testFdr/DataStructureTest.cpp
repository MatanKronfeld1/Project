// test_DataStructure.cpp
#include <gtest/gtest.h>
#include "DataStructure.h"
#include "User.h"
#include "Movie.h"

// Test adding a user by ID and movies
TEST(DataStructureTest, AddUserByIdAndMovies) {
    DataStructure v;
     Movie movie1(1);
    Movie movie2(2);
        std::unordered_set<Movie, Movie::MovieHash> movies = {movie1, movie2};

    v.add_User(100, movies);

        const auto& users = v.get_users();
    ASSERT_EQ(users.size(), 1);
     EXPECT_EQ(users[0].getId(), 100);
      EXPECT_TRUE(users[0].hasWatchedMovie(movie1));
    EXPECT_TRUE(users[0].hasWatchedMovie(movie2));
}

// Test finding a user by ID
TEST(DataStructureTest, FindUserById) {
    DataStructure v;
    User user2(104);
    v.add_User(user2);

    User foundUser = v.find_user(104);
    EXPECT_EQ(foundUser.getId(), 104);
}




// Test finding a user pointer by ID
TEST(DataStructureTest, FindUserPtrById) {
    DataStructure v;
    User user4(16);
    v.add_User(user4);

    User* userPtr = v.find_user_ptr(16);
    ASSERT_NE(userPtr, nullptr);
    EXPECT_EQ(userPtr->getId(), 16);

    userPtr = v.find_user_ptr(30); // Nonexistent user
    EXPECT_EQ(userPtr, nullptr);


}

TEST(DataStructureTest, AddUserDirectly) {
    DataStructure v;
    User user(102);
    Movie movie(40);
    user.addMovie(movie);

    v.add_User(user);

    const auto& users = v.get_users();
    ASSERT_EQ(users.size(), 1);
    EXPECT_EQ(users[0].getId(), 102);
    EXPECT_TRUE(users[0].hasWatchedMovie(movie));
}

// duplicates 
TEST(DataStructureTest, AddDuplicateUserById) {
    DataStructure v;
    Movie movie(9);
    Movie movie1(10);
    std::unordered_set<Movie, Movie::MovieHash> movies = {movie};
    std::unordered_set<Movie, Movie::MovieHash> movies1 = {movie1};

    v.add_User(108, movies);
    v.add_User(108, movies1); 

    const auto& users = v.get_users();
    ASSERT_EQ(users.size(), 1); 
    EXPECT_EQ(users[0].getId(), 108);
    EXPECT_TRUE(users[0].hasWatchedMovie(movie));
    EXPECT_TRUE(users[0].hasWatchedMovie(movie1));
}

// Test checking if a user has watched a specific movie
TEST(DataStructureTest, FindMovieInUser) {
    DataStructure v;
    Movie movie(7);
    Movie movie1(8);
    std::unordered_set<Movie, Movie::MovieHash> movies = {movie};
    v.add_User(1007, movies);

    User* userPtr = v.find_user_ptr(1007);
    ASSERT_NE(userPtr, nullptr);

    EXPECT_TRUE(v.find_movie(*userPtr, movie));
    EXPECT_FALSE(v.find_movie(*userPtr, movie1));
}


