#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H
#include "User.h"
#include <vector>

class DataStructure {
public:
    DataStructure(); //constructor
    void add_User(int id, const std::unordered_set<Movie, Movie::MovieHash>& movies); // Add User to vector of users
    User find_user(int id); //find user by id
    bool find_movie(User &user, Movie &movie); //find if User has watched movie
    const vector <User>  &get_users(); // return users
private:
    vector<User> users;
};

#endif // DATASTRUCTURE_H