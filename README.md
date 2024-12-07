# Project
## Commands to run the project using docker:
```bash
docker build -t part1 .
docker volume create data1
docker run --init it -v data1:/app/data part1
```
NOTE: 
	In order to stop the program from running use: ctrl + C
	To rerun, run the third command above.

## Commands to run the tests using docker: 
NOTE: open the project directory from the terminal. then, run the commands below:
```bash
cd testFdr
docker build -t part1tests .
docker run part1tests
``` 

## Structure of the project:
Our project contains several classes and interfaces as detailed below:
- Movie:
	every instance of this class represents a movie. every movie has an id number.

- User:
	every instance of this class represents a user. each user has an id number and a set of movies he has watched.

- originalDataManager (interface):
	enables data management. contains signatures of functions for uploading the data
	and save it in a data structure, as well as adding new information to the file.

- DataFilesManager (implements "originalDataManager" interface):
	designed to enable data management when the data is saved in a file named dataFile.txt.

- iAlgorithm (interface):
	The purpose of this interface is to enable the use of different algorithms to find recommendations for a user.

- Algorithm1(implements "iAlgorithm" interface):
	This class prints recommendations based on the algorithm given in the project requirements.

- inputManager (interface):
	Enables reading input from several types of resources.

- standardInput (implements "inputManager" interface):
	Handles reading input from the console.

- outputManager (interface):
	Enables writing output to several types of resources.

- standardOutput (implements "outputManager" interface):
	 Handles writing output to the console.

- DataStructure:
	Instances of this class represent the data structure that contains the data. 
	This class contains functions that enable to add a new user, find a user in the data, find a movie and more.

- Icommand (interface):
	The purpose of this interface is to enable adding (and deleting) commands in our program efficiently.

- Add (implements "Icommand" interface):
	This class responsible for the logic required when adding a user. This class uses functions of User class, as well as functions of DataStructure and DataFilesManager.

- Recommend (implements "Icommand" interface):
	This class responsible for the logic required in order to give recommendations to a user.
It uses functions of Algorithm1 class.

- Help (implements "Icommand" interface):
	The purpose of this class is to print the menu.

- App:
	This class is responsible for managing and execute the program.

- main:
	This class contains necessary initializations as well as an instance of App. The class contains a call to the "run" function of App.
