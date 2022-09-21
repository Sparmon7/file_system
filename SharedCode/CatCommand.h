// CatCommand.h
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Header file for a concatenation command, which allows
// the user to either overwrite or concatenate to an existing file.
//

#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "BasicDisplayVisitor.h"

#include <sstream>

class CatCommand : public AbstractCommand {
public:
	CatCommand(AbstractFileSystem*);
	int execute(std::string) override;
	void displayInfo() override;
private:
	AbstractFileSystem* fileSys;
};