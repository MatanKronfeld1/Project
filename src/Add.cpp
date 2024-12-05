#include "Icommand.h"
#include "Add.h"
#include "DataStructure.h"
#include "originalDataManager.h"
#include "DataFilesManager.h"
#include "User.h"
#include "Movie.h"
#include <iostream>
#include <vector>

using namespace std;

bool Add::checkInputValidity(istringstream& stream){
    string token;
    int tokensNum = 0;

    //if there are no tokens
    if(!(stream >> token)){
        return false;
    }
    tokensNum++;
    try{
        int userId = std::stoi(token);
        if(userId < 0){
            return false;
        }
    } catch( ... ) {return false;}

    while(stream >> token){
        tokensNum++;
        try{
            int movieId = std::stoi(token);
            if(movieId < 0){
                return false;
            }
        } catch( ... ) {return false;}
    }
    if(tokensNum < 2){
        return false;
    }
    
    return true;
}

void Add::execute(istringstream& stream, DataStructure* data, originalDataManager* dataManager){
    //copy the stream in order to check it's validity without changing the original parameter
    istringstream tempStream(stream.str());
    vector<Movie> moviesToAdd;
    //if the input is invalid
    if(!checkInputValidity(tempStream)){
        return;
    }
    //gets here only when the input is valid
    string userIdToken;
    stream >> userIdToken;
    int userId;
    int movieId;

    try{ //check on forum!!!
    userId = std::stoi(userIdToken);
    if (userId < 0) { return; }
    } catch ( ... ) { return; }

    string movieIdToken;
    //check if the user already exists
    User* userPtr = data->find_user_ptr(userId);
    //if the user doesn't exists
    if(userPtr == nullptr){
        //create a new user
        User newUser(userId);
        //capture all the other tokens
        while(stream >> movieIdToken){
            try{ //check on forum!!!
            movieId = std::stoi(movieIdToken);
            if(movieId < 0) { return; }
            } catch ( ... ) { return; }
            Movie newMovie(movieId);
            //check if the user hasn't watched the current movie
            //necessary to prevent a case of completely new user with duplicates in his movies
            if(!newUser.hasWatchedMovie(newMovie)){
                //add the new movie to the user
                newUser.addMovie(newMovie);
                moviesToAdd.push_back(newMovie);
            }
        } //end of while loop
        //add the new user to the data structure
        data->add_User(newUser);
        //updates the data file
        dataManager->addRecordToData(newUser, moviesToAdd);
    } else{
        //if the user already exists in the data
        //capture all the other tokens
        while(stream >> movieIdToken){
            try{ //check on forum!!!
            movieId = std::stoi(movieIdToken);
            if(movieId < 0) { return; }
            } catch ( ... ) { return; }
            Movie newMovie(movieId);
            //if the user hasn't watched the current movie
            if(!userPtr->hasWatchedMovie(newMovie)){
                userPtr->addMovie(newMovie);
                moviesToAdd.push_back(newMovie);  
            }
        } //end of while loop
        //if the vector is not empty it means that there are movies to add to the file
        if(!moviesToAdd.empty()){
            dataManager->addMoviesToUser(*userPtr, moviesToAdd);
        }
    }
}