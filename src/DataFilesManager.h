#ifndef DATA_FILES_MANAGER_H
#define DATA_FILES_MANAGER_H

#include "originalDataManager.h"
#include "DataStructure.h"
#include "User.h"
#include "Movie.h"
#include <vector>

class DataFilesManager : public originalDataManager {
public:
    //add constructor?

    DataStructure* uploadData() override;
    void addMoviesToUser(User user, const vector <Movie>  &moviesToAdd) override;
    void addRecordToData(User user, const vector <Movie>  &moviesToAdd) override;


};


#endif