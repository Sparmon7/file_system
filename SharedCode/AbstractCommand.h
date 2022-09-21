// AbstractCommand.h
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Interface for a command, serves as a base
// for all further derived commands. Includes enum for return values.
//

#pragma once

#include <string>
#include <sstream>

class AbstractCommand {
public:
	virtual int execute(std::string) = 0;
	virtual void displayInfo() = 0;
	virtual ~AbstractCommand() = default;
};

//return values for all derived classes of AbstractCommand
enum struct retValues{success = 0, quit = 1, notCreated = 2, notAdded =3, ErrorReading = 5, unableToDo = 6, fileDoesNotExist = 7, duplicateName = 8, noName = 9};