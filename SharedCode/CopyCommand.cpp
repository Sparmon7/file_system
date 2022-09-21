// CopyCommand.cpp
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Definitions for a copy command, which allows the user
// to copy an existing file.
//

#include "CopyCommand.h"

using namespace std;

//constructor
CopyCommand::CopyCommand(AbstractFileSystem* s) : fileSys(s) { }

//execute function, will return value indicating success or appropriate error value
int CopyCommand::execute(std::string name) {
	vector<string> inputs;
	stringstream s(name);
	string word;

	//add user input to vector
	while (s >> word) {
		inputs.push_back(word);
	}
	
	//get list of all names in file system
	set<string> names = fileSys->getFileNames();

	//if file does not exist, display error and exit with appropriate return value
	if (names.find(inputs[0]) == names.end()) {
		cout << "File does not exist" << endl;
		return static_cast<int>(retValues::fileDoesNotExist);
	}

	//make sure supplied a name
	if (inputs.size() < 2) {
		cout << "needed to supply a name for the new file." << endl;
		return static_cast<int>(retValues::noName);
	}

	//check if filename already exists
	string delimiter = ".";
	string no_extension;
	for (string s : names) {
		no_extension = s.substr(0, s.find(delimiter));
		if (no_extension == inputs[1]) {
			cout << "A file with this name already exists" << endl;
			return static_cast<int>(retValues::duplicateName);
		}
	}


	

	//if all good, clone file
	AbstractFile* temp = fileSys->openFile(inputs[0]);
	AbstractFile* add = temp->clone(inputs[1]);
	//return error if unable to
	if (add == nullptr) {
		return static_cast<int>(retValues::unableToDo);
	}
	//if successful, add new file and exit with success
	fileSys->addFile(add->getName(), add);
	fileSys->closeFile(temp);
	return static_cast<int>(retValues::success);
}

//display info function
void CopyCommand::displayInfo() {
	cout << "Create a copy of a file by writing copy <filetocopy> <newnamewithoutextension>" << endl;
}
