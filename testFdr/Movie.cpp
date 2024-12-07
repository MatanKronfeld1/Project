#include "Movie.h"
# include <functional>


    Movie :: Movie(int movie_id) {
        id = movie_id;
    }


    int Movie::getId() const {
      return id;
    }

    // Equality operator (needed for unordered_set)
    bool Movie::operator==(const Movie& other) const {
        return id == other.id;
    }

    // Hash function to hash Movies based on their id
size_t Movie::MovieHash::operator()(const Movie& movie) const {
    return std::hash<int>()(movie.getId());  // Use the built-in hash function for integers
}