
#ifndef USER_H
#define USER_H
#include <vector>
#include "Movie.h"

using namespace std;

class User {
    private:
        int id;
        vector<Movie> watchedMovies;
    public:
        User(int userId);
        void addMovie(Movie movie);
        void addMovies(const vector <Movie>  &movies);
        int getId();

};

#endif
