// AbstractFileSystem.h
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Interface for a file system to be used in derived classes
//

#pragma once

#include "AbstractFile.h"

#include<vector>
#include<string>
#include <iostream>
#include <set>

class AbstractFileSystem {
public:
	virtual int  addFile(std::string, AbstractFile*) = 0;
	virtual int  deleteFile(std::string) = 0;
	virtual AbstractFile* openFile(std::string) = 0;
	virtual int closeFile(AbstractFile*) = 0;
	virtual std::set<std::string> getFileNames() = 0;
};