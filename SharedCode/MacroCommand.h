// MacroCommand.h
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Header file for a macro command, which takes a parsing
// strategy to combine two already defined commands into a new one.
//

#pragma once

#include "AbstractCommand.h"
#include "AbstractParsingStrategy.h"
#include "AbstractFileSystem.h"

#include <iomanip>

class MacroCommand : public AbstractCommand {
public:
	MacroCommand(AbstractFileSystem*);
	void addCommand(AbstractCommand*);
	void setParseStrategy(AbstractParsingStrategy*);
	int execute(std::string) override;
	void displayInfo() override;
private:
	AbstractFileSystem* fileSys;
	AbstractParsingStrategy* aps;
	std::vector<AbstractCommand*> commands;
};