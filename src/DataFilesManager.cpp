#include "DataFilesManager.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

/*#include "User.h"
#include "Movie.h"
#include "DataStructure.h"*/

DataStructure* DataFilesManager::uploadData(){
    //try to open the file that contains the data of the project in read and write mode
    std::fstream inputFile("../data/dataFile.txt", std::ios::in | std::ios::out);
    //if the file doesn't exist - create it
    if(!inputFile){
        inputFile.open("../data/dataFile.txt", std::ios::out);
        if(!inputFile){
            //error with creating file
            return nullptr;
        }
        //close and reopen the file for reading
        inputFile.close();
        inputFile.open("../data/dataFile.txt");
    }

    DataStructure* dataStructure = new DataStructure();
    std::string currentLine;

    //as long as there are lines to read in the file, read line by line
    while(std::getline(inputFile, currentLine)){
        //in order to process the line
        //the format of every line is: UserId Movie1Id Movie2Id ...
        std::stringstream strStream(currentLine);
        int userId;
        int movieId;
        //extract the user id
        strStream >> userId;
        User newUser(userId);
        //as long as the extraction succeeds
        while(strStream >> movieId){
            Movie newMovie(movieId);
            newUser.addMovie(newMovie);
        }
        //TO DO: call the above func from here. check how to add to dataStructure because its a reference
        dataStructure->add_User(newUser);
    }
    inputFile.close();
    return dataStructure;
}

/*
this function append movies to a given user that is already exist in the file
*/
void DataFilesManager::addMoviesToUser(User user, const vector <Movie>  &moviesToAdd){
    //open the file in read and write mode
    std::fstream inputFile("../data/dataFile.txt", std::ios::in | std::ios::out);
    if(!inputFile){
        //error in opening file
        return;
    }
    std::string currentLine;
    //std::string modifiedData;
    std::stringstream modifiedData;
    bool isUserFound = false;

    //read the entire file
    while (std::getline(inputFile, currentLine)){
        std::stringstream strStream(currentLine);
        int currentUserId;
        strStream >> currentUserId;

        //check if the current userId equals to user.id
        if(currentUserId == user.getId()){
            //we found the relevant line that represents the data of the user
            isUserFound = true;
            //in order to keep the format of the file
            currentLine += " ";
            //append each movie Id from the vector to the end of the line
            for(const Movie& movie : moviesToAdd){
                currentLine += std::to_string(movie.getId()) + " ";
            }
        }
        //add the line (modified or original) to the modified content stream
        modifiedData << currentLine << std::endl;
    } //end of while loop

    //close the file in order to write changes back
    inputFile.close();
    //open the file again in write mode (to rewrite it)
    std::ofstream outputFile("../data/dataFile.txt", std::ios::out | std::ios::trunc);
    if(!outputFile){
        //error in opening file
        return;
    }
    //write the new and modified data to the file
    outputFile << modifiedData.str();
    outputFile.close();
}

void DataFilesManager::addRecordToData(User user, const vector <Movie>  &moviesToAdd){
    //open the file in reading mode in order to add the data to the end of the file
    /*std::ifstream inputFile("../data/dataFile.txt", std::ios::in);
    if(!inputFile){
        //error in opening file
        return;
    }
    bool isEmptyFile = inputFile.peek() == std::ifstream::traits_type::eof();
    inputFile.close();*/
    //open the file in append mode in order to add the data to the end of the file
    std::ofstream outputFile("../data/dataFile.txt", std::ios::out | std::ios::app);
    if(!outputFile){
       //error in opening file
        return; 
    }
    //start a new line for the new record
    outputFile << std::endl;
    //write the user Id at the begginig of a new line at the end of the file
    outputFile << user.getId();
    //append every movie Id if every movie in the movies vector to the line
    for(const Movie& movie : moviesToAdd){
        outputFile << " " << movie.getId();
    }
    //outputFile << std::endl;
    outputFile.close();
}
