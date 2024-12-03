# include "DataStructure.h"
# include <iostream>
#include <algorithm>

// Constructor
DataStructure::DataStructure() {
    users = vector<User>();
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

bool DataStructure :: find_movie(User &user, Movie &movie) {
    return user.getWatchedMovies().find(movie) != user.getWatchedMovies().end();
}

void DataStructure::add_User(int id, const std::unordered_set<Movie, Movie::MovieHash>& movies) {
    // Check if the user already exists by iterating through the users vector
    for (User &user : users) {
        if (user.getId() == id) {
            // User exists, add the movies
            user.addMovies(movies);
            return;
        }
    }

    // User does not exist, create a new user and add the movies
    User newUser(id);
    newUser.addMovies(movies);
    users.push_back(newUser);
}

const vector <User> &DataStructure:: get_users(){
    return users;
}

