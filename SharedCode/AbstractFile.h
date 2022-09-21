// AbstractFile.h
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Interface for a file, serves as a base
// for all further derived file types. Includes enum for return values.
//

#pragma once

#include "AbstractFileVisitor.h"

#include<vector>
#include<string>
#include <iostream>

class AbstractFile {
public:
	virtual ~AbstractFile() = default;
	virtual std::vector<char> read() = 0;
	virtual int  write(std::vector<char>) = 0;
	virtual int  append(std::vector<char>) = 0;
	virtual unsigned int  getSize() = 0;
	virtual std::string  getName() = 0;
	virtual void accept(AbstractFileVisitor *) = 0;
	virtual AbstractFile* clone( std::string ) = 0;
};

//return values for all derived file types
enum struct outcomes { SUCCESS = 0, ERROR = -1, NA = -2, ERROR_WRITING = -3, NULL_POINTER = -4, EXISTS = -5, SIZE_MISMATCH = -6, WRONG_TYPE = 2, DOES_NOT_EXIST = 3, OPEN = 4, NOT_OPEN = 5 };
//enum for vector location
enum struct index { FIRST = 0, ERROR = -1 };