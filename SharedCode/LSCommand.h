// LSCommand.h
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Header file for an ls command, which allows the user
// to display a list of files in a file system
//

#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "MetadataDisplayVisitor.h"

#include <iomanip>

class LSCommand : public AbstractCommand {
public:
	LSCommand(AbstractFileSystem*);
	int execute(std::string) override;
	void displayInfo() override;
private:
	AbstractFileSystem* fileSys;
};

enum struct info { size = 25 };