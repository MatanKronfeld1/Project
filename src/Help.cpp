#include "Icommand.h"
#include "Help.h"
#include "iAlgorithm.h"
#include "Algorithm1.h"
#include "originalDataManager.h"
#include <iostream>

using namespace std;

void Help::execute(istringstream& stream, DataStructure* data, originalDataManager* dataManager) {
    cout << "add [userid] [movieid1] [movieid2] ..." << endl;
    cout << "recommend [userid] [movieid]" << endl;
    cout << "help" << endl;
    return;
}
    

