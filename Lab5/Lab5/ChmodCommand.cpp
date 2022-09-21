// ChmodCommand.cpp
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Definitions for a chmod command, which allows the
// user to make files read-only/writable
//

#include "ChmodCommand.h"

using namespace std;

//constructor
ChmodCommand::ChmodCommand(AbstractFileSystem* s, AbstractFileFactory* f) : fileSys(s), fileFac(f) { }

//execute function, returns a value indicating a success or appropriate failure
int ChmodCommand::execute(std::string name) {
	vector<string> inputs;
	stringstream s(name);
	string word;

	//push user inputs into vector
	while (s >> word) {
		inputs.push_back(word);
	}

	AbstractFile* ret = fileFac->createFile(inputs[0]);
	if (ret != nullptr) {
		if (inputs.size() > 1) {
			set<string> a = fileSys->getFileNames();
			if (a.find(inputs[0]) != a.end()) {
				AbstractFile* file = fileSys->openFile(inputs[0]);
				AbstractFile* PP = file->clone(name);
				PP = new ChmodProxy(PP, name);
				fileSys->closeFile(file);
				
				if (fileSys->deleteFile(inputs[0]) != 0) {
					delete ret;
					return static_cast<int>(retValues::notAdded);
				}
				else {
					if (fileSys->addFile(inputs[0], PP) != 0) {
						return static_cast<int>(retValues::notAdded);
					}
					return static_cast<int>(retValues::success);
				}
			}
			else {
				AbstractFile* PP = new ChmodProxy(ret, name);
				if (fileSys->addFile(inputs[0], PP) != 0) {
					delete ret;
					return static_cast<int>(retValues::notAdded);
				}
				return static_cast<int>(retValues::success);
			}
		}
	}
	return static_cast<int>(retValues::notCreated);
}

//display command
void ChmodCommand::displayInfo() {
	cout << "chmod creates a file, chmod must be invoked with the command : touch < filename> <+ or ->" << endl;
}