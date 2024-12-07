#include <gtest/gtest.h>
#include "User.h"
#include "Movie.h"

// Test the constructor and getId method
TEST(UserTest, ConstructorAndGetId) {
    User user(1001); // Create a user with ID 1001
    EXPECT_EQ(user.getId(), 1001); // Verify the ID is set correctly
}

// Test adding a single movie
TEST(UserTest, AddSingleMovie) {
    User user(1001);
    Movie movie(42);

    user.addMovie(movie);

    // Check if the movie is in the watched set
    EXPECT_TRUE(user.hasWatchedMovie(movie));
    EXPECT_EQ(user.getWatchedMovies().size(), 1); // Only one movie should be in the set
}

// Test adding multiple movies
TEST(UserTest, AddMultipleMovies) {
    User user(1001);
    Movie movie1(42);
    Movie movie2(43);
    Movie movie3(44);

    std::unordered_set<Movie, Movie::MovieHash> movies = {movie1, movie2, movie3};
    user.addMovies(movies);

    // Check if all movies are in the watched set
    EXPECT_TRUE(user.hasWatchedMovie(movie1));
    EXPECT_TRUE(user.hasWatchedMovie(movie2));
    EXPECT_TRUE(user.hasWatchedMovie(movie3));
    EXPECT_EQ(user.getWatchedMovies().size(), 3); // Three movies should be in the set
}

// Test the watched set remains unique
TEST(UserTest, AddDuplicateMovies) {
    User user(1001);
    Movie movie1(42);
    Movie movie2(42); // Same ID as movie1

    user.addMovie(movie1);
    user.addMovie(movie2); // Adding a duplicate

    // The set should only contain one movie because duplicates aren't allowed
    EXPECT_EQ(user.getWatchedMovies().size(), 1);
    EXPECT_TRUE(user.hasWatchedMovie(movie1));
}

// Test getWatchedMovies method
TEST(UserTest, GetWatchedMovies) {
    User user(1001);
    Movie movie1(42);
    Movie movie2(43);

    user.addMovie(movie1);
    user.addMovie(movie2);

    const auto& watched = user.getWatchedMovies();
    EXPECT_EQ(watched.size(), 2);
    EXPECT_TRUE(watched.find(movie1) != watched.end());
    EXPECT_TRUE(watched.find(movie2) != watched.end());
}
