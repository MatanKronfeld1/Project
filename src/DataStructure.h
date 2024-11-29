#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H
#include "User.h"

class DataStructure {
public:
    DataStructure(); //constructor
    void add_User(int id, vector <Movie>  &movies); //adUser to vector of users
    User find_user(int id); //find user by id
    bool find_movie(User user, Movie movie); //find if User has watched movie
private:
    vector<User> users;
};

#endif // DATASTRUCTURE_H