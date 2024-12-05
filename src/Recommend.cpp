#include "Icommand.h"
#include "Recommend.h"
#include "iAlgorithm.h"
#include "Algorithm1.h"
#include "originalDataManager.h"
#include <iostream>

using namespace std;

using namespace std;

void Recommend::execute(istringstream& stream, DataStructure* data, originalDataManager* dataManager) {
    string arg1;
    string arg2;
    stream >> arg1;
    stream >> arg2;
    try{
    int user_id = std::stoi(arg1);
    if (user_id < 0) { return; }
    } catch ( ... ) { return; }
    try {
    int movie_id = std::stoi(arg2);
    } catch ( ... ) { return; }
    Algorithm1 algorithm1;
    vector <int> recs = algorithm1.recommend(*data, std::stoi(arg1), std::stoi(arg2));
    

    // making it ready for printing
    string output;
    for (int i = 0; i < recs.size(); i++) {
        output += to_string(recs[i]);
        if (i != recs.size() - 1) {
            output += " ";
        }
    }
    cout << output << endl;
    return;
}
    

