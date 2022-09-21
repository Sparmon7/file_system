// RemoveCommand.cpp
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Definitions for a remove command, which allows the
// user to remove a file from a file system.
//

#include "RemoveCommand.h"

using namespace std;

//constructor
RemoveCommand::RemoveCommand(AbstractFileSystem* s) : fileSys(s) { }

//execute function, will return success or appropriate error value
int RemoveCommand::execute(std::string name) {
	int del = fileSys->deleteFile(name);
	return del;
}

//display info command
void RemoveCommand::displayInfo() {
	cout << "remove a specified file, by rm <file name>" << endl;
}