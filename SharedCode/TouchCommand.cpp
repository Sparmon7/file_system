// TouchCommand.cpp
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Definitions for a touch command, which allows the user
// to create and add a file to a file system.
//

#include "TouchCommand.h"

using namespace std;

//constructor
TouchCommand::TouchCommand(AbstractFileSystem* s, AbstractFileFactory* f): fileSys(s), fileFac(f) { }

//execute funtion, will return success or appropriate error value
int TouchCommand::execute(std::string name) {
	vector<string> inputs;
	stringstream s(name);
	string word;

	//add user inputs to vector
	while (s >> word) {
		inputs.push_back(word);
	}
	
	//create new file
	AbstractFile * ret = fileFac->createFile(inputs[0]);

	//if successfully made
	if (ret != nullptr) {
		if (inputs.size() > 1) {
			//if -p invoked, create password proxy for file
			if (inputs[1] == "-p") {
				string pass;

				cout << "Please type in a password" << endl;
				getline(cin, pass);

				AbstractFile* PP = new PasswordProxy(ret, pass);

				//if error in adding file, delete new file and return appropriate error
				if (fileSys->addFile(inputs[0], PP) != 0) {
					delete ret;
					return static_cast<int>(retValues::notAdded);
				}
			}

			//otherwise return success
			return static_cast<int>(retValues::success);	
		}
		
		//if not password protected, add regular file
		else {
			if (fileSys->addFile(inputs[0], ret) != 0) {
				delete ret;
				return static_cast<int>(retValues::notAdded);
			}

			return static_cast<int>(retValues::success);
		}
	}

	//otherwise error in creating file
	return static_cast<int>(retValues::notCreated);
}

//display info command
void TouchCommand::displayInfo() {
	cout << "touch creates a file, touch can be invoked with the command : touch < filename>, password protecting the file can be done with -p" << endl;
}