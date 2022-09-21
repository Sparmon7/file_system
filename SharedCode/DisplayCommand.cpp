// DisplayCommand.cpp
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Definitions for a display command, which allows the
// user to display the contents of a file.
//

#include "DisplayCommand.h"

using namespace std;

//constructor
DisplayCommand::DisplayCommand(AbstractFileSystem* s) : fileSys(s) { }

//execute function, will return value indicating success or appropriate error value
int DisplayCommand::execute(std::string name) {
	vector<string> inputs;
	stringstream s(name);
	string word;

	//add user inputs to a vector
	while (s >> word) {
		inputs.push_back(word);
	}

	//get list of all names in file system
	set<string> names = fileSys->getFileNames();

	//if file does not exits, diplay error and exit with appropriate return value
	if (names.find(inputs[0]) == names.end()) {
		cout << "File does not exist" << endl;
		return static_cast<int>(retValues::fileDoesNotExist);
	}

	//if user wishes to see unformatteed data, display unformated data
	if (inputs.size() > 1 && inputs[1] == "-d") {
		AbstractFile* file = fileSys->openFile(inputs[0]);
		vector<char> contents = file->read();
		for (int i = 0; i < contents.size(); ++i) {
			cout << contents[i];
		}
		cout << endl;
		fileSys->closeFile(file);
	}
	//otherwise display formatted
	else {
		AbstractFileVisitor* blank = new BasicDisplayVisitor();
		AbstractFile * file = fileSys->openFile(inputs[0]);
		file->accept(blank);
		delete blank;
		fileSys->closeFile(file);
	}

	return static_cast<int>(retValues::success);
}

//display info command
void DisplayCommand::displayInfo() {
	cout << "display the contents of a file, by ds <file name> or ds <file name> -d to have it viewed unformatted" << endl;
}
