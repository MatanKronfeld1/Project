#include "User.h"

// Constructor: Initializes the user with an ID
User::User(int userId) : id(userId) {}

// Add a single movie to the watched set
void User::addMovie(const Movie& movie) {
    watchedMovies.insert(movie);
}

// Add multiple movies to the watched set
void User::addMovies(const unordered_set<Movie, Movie::MovieHash>& movies) {
    watchedMovies.insert(movies.begin(), movies.end());
}

// Get the user ID
int User::getId() const {
    return id;
}

// Get the unordered set of watched movies
const unordered_set<Movie, Movie::MovieHash>& User::getWatchedMovies() const {
    return watchedMovies;
}

// Check if the user has watched a movie
bool User::hasWatchedMovie(const Movie& movie) const {
    return watchedMovies.find(movie) != watchedMovies.end();
}


