// TouchCommand.h
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Header file for a touch command, which allows the user
// to create and add a file to a file system.
//

#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "PasswordProxy.h"

#include <sstream>

class TouchCommand: public AbstractCommand {
public:
	TouchCommand(AbstractFileSystem*, AbstractFileFactory*);
	int execute(std::string) override;
	void displayInfo() override;
private:
	AbstractFileSystem* fileSys;
	AbstractFileFactory* fileFac;
};