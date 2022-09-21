// CommandPrompt.h
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Header file for command prompt, which stores and runs
// a set list of commands.
//

#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

#include <map>

class CommandPrompt {
private:
	AbstractFileSystem * fileSys;
	AbstractFileFactory* fileFac;
	std::map<std::string, AbstractCommand*> mappy;
protected:
	void listCommands();
	std::string prompt();
public:
	CommandPrompt() = default;
	void setFileSystem(AbstractFileSystem*);
	void setFileFactory(AbstractFileFactory*);
	int addCommand(std::string, AbstractCommand*);
	int run();
};