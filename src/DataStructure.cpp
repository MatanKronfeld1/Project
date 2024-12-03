# include "DataStructure.h"
# include <iostream>
# include <algorithm>

// Constructor
DataStructure::DataStructure() {
    users = vector<User>();
}

vector<User>& DataStructure::getUsersVector(){
    return users;
}

User DataStructure::find_user(int id) {
    try {
        for (User &user : users) {
            if (user.getId() == id) {
                return user;
            }
        }
        throw "User not found";
    } catch (...) {
        throw;
    }
}

bool DataStructure :: find_movie(User user, Movie movie) {
    vector<Movie> movies = user.getWatchedMovies();
    for (Movie &film : movies) {
        if (film.getId() == movie.getId()) {
            return true;
        }
    }
    return false;
}

void DataStructure::add_User(int id, vector <Movie> &movies) {
    for (User &user : users) {
        if (user.getId() == id) {
            for (Movie &movie : movies) {
                if (!find_movie(user, movie)) {
                    user.addMovie(movie);
                }
            }
            return;
        }
    }
    User newUser(id);
    newUser.addMovies(movies);
    users.push_back(newUser);
}

void DataStructure::add_User(User newUser) {
    users.push_back(newUser);
}