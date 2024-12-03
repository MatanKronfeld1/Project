#ifndef ORIGINAL_DATA_MANAGER_H
#define ORIGINAL_DATA_MANAGER_H

//include DataStructure header file
#include "DataStructure.h"
#include "User.h"
#include "Movie.h"
using namespace std;

/*
an abstract class that is used as interface to handle
managing data that is saved in several types of resources like files etc.
*/

class originalDataManager{
public:
    /*
    function that returns a pointer to DataStructure instance.
    this func create DataStructure instance, scan the data resource and meanwhile
    update the instance and add values to it. then, returns a pointer.
    */
    virtual DataStructure* uploadData()=0;

    /*
    will be used in case when we need to add movie/movies to an existing user
    parameteters: user and a vector of the movies we need to add. the vector 
    is passed by a constant reference so it is "read only".
    the function will search the user in the data and then add the movies to him.
    */
    virtual void addMoviesToUser(User user, const vector <Movie>  &moviesToAdd){
        return;
    }

    /*
    will be used in case when we need to add a completely new user and it's movies.
    parameteters: user and a vector of the movies we need to add. the vector 
    is passed by a constant reference so it is "read only".
    the function will add the imformation to the end of the data. 
    */
    virtual void addRecordToData(User user, const vector <Movie>  &moviesToAdd){
        return;
    }

};


#endif