// CopyCommand.h
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Header file for a copy command, which allows the user
// to copy an existing file.
//

#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "MetadataDisplayVisitor.h"

#include <iomanip>

class CopyCommand : public AbstractCommand {
public:
	CopyCommand(AbstractFileSystem*);
	int execute(std::string) override;
	void displayInfo() override;
private:
	AbstractFileSystem* fileSys;
};

