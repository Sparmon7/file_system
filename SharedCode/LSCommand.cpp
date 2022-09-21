// LSCommand.cpp
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Definitions for an ls command, which allows the user
// to display a list of files in a file system
//

#include "LSCommand.h"

using namespace std;

//constructor
LSCommand::LSCommand(AbstractFileSystem* s) : fileSys(s) { }

//execute function, will return value indicating success or appropriate error value
int LSCommand::execute(std::string name) {
	//get names of all files in file system
	set<string> names = fileSys->getFileNames();
	
	//if -m is invoked, display files with metadata
	if (name == "-m") {
		for (set<string>::iterator it = names.begin(); it != names.end(); ++it) {
			AbstractFileVisitor* abVis = new MetadataDisplayVisitor();
			AbstractFile* name = fileSys->openFile(*it);
			
			name->accept(abVis);
			delete abVis;
			
			fileSys->closeFile(name);
		}
	}

	//otherwise display files in list format
	else  {
		int count = 0; 
		for (set<string>::iterator it = names.begin(); it != names.end(); ++it) {
			if (count % 2 != 0) {
				cout << *it << endl;
			}
			else {
				cout << *it << setw(static_cast<int>(info::size));
			}
			count++;	
		}
		cout << setw(0) <<  endl;
		if (count % 2 != 0) {
			cout  << endl;
		}
	}

	return static_cast<int>(retValues::success);
}

//display info function
void LSCommand::displayInfo() {
	cout << "ls lists the files, if called with -m , it will print the metadata of each file" << endl;
}