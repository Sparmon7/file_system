// AbstractFileFactory.h
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Interface for a file factory to be used in derived classes.
//

#pragma once

#include "AbstractFile.h"

#include <string>

class AbstractFileFactory{
public:
	virtual AbstractFile* createFile(std::string name) = 0;
};