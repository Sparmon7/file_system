// SimpleFileFactory.h
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Definitions for a file factory.
//

#include "SimpleFileFactory.h"
#include "ImageFile.h"
#include "TextFile.h"

using namespace std;

//create file function
AbstractFile* SimpleFileFactory::createFile(std::string str) {
	size_t index = str.find(".");

	if (index == string::npos) {
		return nullptr;
	}

	string ext = str.substr(index + 1);

	if (ext == "img") {
		return new ImageFile(str);
	}

	else if (ext == "txt") {
		return new TextFile(str);
	}
	
	return nullptr;
}