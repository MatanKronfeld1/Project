#ifndef USER_H
#define USER_H

#include <unordered_set>
#include "Movie.h"

using namespace std;

class User {
private:
    int id;
    std::unordered_set<Movie, Movie::MovieHash> watchedMovies;

public:
    // Constructor to initialize the user with an ID
    User(int userId);

    // Add a single movie to the watched set
    void addMovie(const Movie& movie); // Pass by const reference

    // Add multiple movies to the watched set
    void addMovies(const unordered_set<Movie, Movie::MovieHash>& movies);

    // Get the ID of the user
    int getId() const;

    // Get the unordered set of watched movies (returning const reference to prevent modification)
    const unordered_set<Movie, Movie::MovieHash>& getWatchedMovies() const;

    // check if user has watched a movie
    bool hasWatchedMovie(const Movie& movie) const;
};

#endif // USER_H
