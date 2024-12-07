// test_Movie.cpp
#include <gtest/gtest.h>
#include "Movie.h"

// Test the constructor and getId method
TEST(MovieTest, ConstructorAndGetId) {
    Movie movie(42); // Create a Movie object with id = 42
    EXPECT_EQ(movie.getId(), 42); // Verify the id is set correctly
}

// Test the equality operator
TEST(MovieTest, EqualityOperator) {
    Movie movie1(1);
    Movie movie2(1);
    Movie movie3(2);

    EXPECT_TRUE(movie1 == movie2); // Two movies with the same id should be equal
    EXPECT_FALSE(movie1 == movie3); // Two movies with different ids should not be equal
}

// Test the hash function
TEST(MovieTest, MovieHash) {
    Movie::MovieHash hasher;
    Movie movie1(1);
    Movie movie2(2);

    EXPECT_NE(hasher(movie1), hasher(movie2)); // Different ids should produce different hashes
    EXPECT_EQ(hasher(movie1), hasher(Movie(1))); // Same ids should produce the same hash
}

// Main function to run all tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
