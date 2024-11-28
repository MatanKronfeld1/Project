#include "User.h"


User::User(int userId) : id(userId) {}

void User::addMovie(Movie movie) {
  watchedMovies.push_back(movie);
}

void User::addMovies(const vector <Movie> &movies) {
  for (const Movie &movie : movies) {
    watchedMovies.push_back(movie);
    }
  }
int User::getId() {
  return id;
}
