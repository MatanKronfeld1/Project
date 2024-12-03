#ifndef MOVIE_H
#define MOVIE_H

#include <cstddef>

class Movie {
public:
    Movie(int movie_id);
    int getId() const;
    bool operator==(const Movie& other) const;
    struct MovieHash {
        size_t operator()(const Movie& movie) const;
    };
private:
    int id;
};
#endif
