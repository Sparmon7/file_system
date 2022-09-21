// SimpleFileSystem.cpp
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Definitions for a file system, which allows the user
// to store and perform commands on files.
//

#include "SimpleFileSystem.h"
#include "ImageFile.h"
#include "TextFile.h"

using namespace std;

//add file function, will return success or appropriate error value
int  SimpleFileSystem::addFile(std::string str, AbstractFile* file) {
	if(allFiles.find(str) != allFiles.end()){
		return static_cast<int>(outcomes::EXISTS);
	}

	if (file == nullptr) {
		return static_cast<int>(outcomes::NULL_POINTER);
	}

	allFiles.insert( pair<string, AbstractFile*>(str, file) );
	return static_cast<int>(outcomes::SUCCESS);
}

//delete file function, will return success or appropriate error value
int  SimpleFileSystem::deleteFile(std::string str) {
	if (allFiles.find(str) == allFiles.end()) {
		return static_cast<int>(outcomes::DOES_NOT_EXIST);
	}
	AbstractFile* file = allFiles[str];
	if (openFiles.find(file) == openFiles.end()) {
		allFiles.erase(str);
		delete file;
		return static_cast<int>(outcomes::SUCCESS);

	}
	return static_cast<int>(outcomes::OPEN);


}

//open file function, will return pointer to opened file
AbstractFile* SimpleFileSystem::openFile(std::string str) {
	if (allFiles.find(str) == allFiles.end()) {
		return nullptr;
	}
	AbstractFile* file = allFiles[str];
	if (openFiles.find(file) == openFiles.end()) {
		openFiles.insert(file);
		return file;

	}
	
	return nullptr;
}

//close file file function, will return success or appropriate error value
int SimpleFileSystem::closeFile(AbstractFile* file) {
	if (openFiles.find(file) != openFiles.end()) {
		openFiles.erase(file);
		return static_cast<int>(outcomes::SUCCESS);

	}
	return static_cast<int>(outcomes::NOT_OPEN);
}

//get file names function, will return a set of all file names
set<string> SimpleFileSystem::getFileNames() {
	set<string> names;
	for (map <string, AbstractFile*>::iterator it = allFiles.begin(); it != allFiles.end(); it++) {
		names.insert(it->first);

	}
	return names;
}