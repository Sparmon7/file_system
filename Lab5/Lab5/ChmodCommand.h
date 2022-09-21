// ChmodCommand.h
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Header file for a chmod command, which allows the
// user to make files read-only/writable
//

#pragma once

#include "ChmodProxy.h"
#include "..\..\\SharedCode\AbstractCommand.h"
#include "..\..\\SharedCode\AbstractFileSystem.h"
#include "..\..\\SharedCode\AbstractFileFactory.h"

#include <sstream>

class ChmodCommand : public AbstractCommand {
public:
	ChmodCommand(AbstractFileSystem*, AbstractFileFactory*);
	int execute(std::string) override;
	void displayInfo() override;
private:
	AbstractFileSystem* fileSys;
	AbstractFileFactory* fileFac;
};