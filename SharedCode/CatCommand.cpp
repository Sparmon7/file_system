// CatCommand.cpp
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Definitions for a concatenation command, which allows
// the user to either overwrite or concatenate to an existing file.
//

#include "CatCommand.h"

using namespace std;

//constructor
CatCommand::CatCommand(AbstractFileSystem* s) : fileSys(s) { }

//execute command, will return a value indicating a success or an error type
int CatCommand::execute(std::string name) {
	vector<string> inputs;
	stringstream s(name);
	string word;
	bool append = false;

	//add inputs to a vector
	while (s >> word) {
		inputs.push_back(word);
	}
	
	//get list of all names in file system
	set<string> names = fileSys->getFileNames();

	//if desired file does not exists, print out error message and return appropriate value
	if (names.find(inputs[0]) == names.end()) {
		cout << "File does not exist" << endl;
		return static_cast<int>(retValues::fileDoesNotExist);
	}

	//check to see if -a has been invoked
	if (inputs.size() > 1 && inputs[1] == "-a") append = true;

	//if append is called, create temporary file
	if (append) {
		AbstractFileVisitor* blank = new BasicDisplayVisitor();
		AbstractFile* temp = fileSys->openFile(inputs[0]);
		temp->accept(blank);
		delete blank;
		fileSys->closeFile(temp);
	}

	cout << "Enter the data you would like to add to the file.Enter :wq to save the file and exit, enter : q to exit without saving" << endl;
	string add;

	//get user input to append/overwrite
	while (true) {
		bool save = false;
		string toAdd;
		getline(cin, toAdd);
		
		if (toAdd == ":wq") {
			add.erase(add.end() - 1);
			save = true;
			cout << endl;
			break;
		}

		//if user wishes to quit without saving, return success
		if (toAdd == ":q") {
			cout << endl;
			return static_cast<int>(retValues::success);
		}

		add += toAdd;
		add += "\n";
	}

	vector<char> data(add.begin(), add.end());
	AbstractFile* temp = fileSys->openFile(inputs[0]);
	fileSys->closeFile(temp);
	
	//if append is true, append new data to end of file
	if (append) {
		return temp->append(data);
	}
	
	//otherwise overwrite the data in the file
	return temp->write(data);
}

//display info for cat command
void CatCommand::displayInfo() {
	cout << "add things to the end of the file, by cat <file name>, using -a displays the file first" << endl;
}