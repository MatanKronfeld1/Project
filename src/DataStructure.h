#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H
#include "User.h"

class DataStructure {
public:
    DataStructure(); //constructor
    vector<User>& getUsersVector();
    void add_User(int id, vector <Movie>  &movies); //addd User to vector of users
    /*
    this func add completely new user to the users vector
    there is no need to check if the user is already in the users vector because
    this function is being read when we upload the data for the first time
    */
    void add_User(User newUser);
    User find_user(int id); //find user by id
    bool find_movie(User user, Movie movie); //find if User has watched movie
private:
    vector<User> users;
};

#endif // DATASTRUCTURE_H