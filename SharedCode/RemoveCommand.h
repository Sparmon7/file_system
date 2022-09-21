// RemoveCommand.h
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Header file for a remove command, which allows the
// user to remove a file from a file system.
//

#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class RemoveCommand : public AbstractCommand {
public:
	RemoveCommand(AbstractFileSystem*);
	int execute(std::string) override;
	void displayInfo() override;
private:
	AbstractFileSystem* fileSys;
};