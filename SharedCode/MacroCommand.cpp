// MacroCommand.cpp
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Definitions for a macro command, which takes a parsing
// strategy to combine two already defined commands into a new one.
//

#include "MacroCommand.h"

#include <iostream>

//constructor
MacroCommand::MacroCommand(AbstractFileSystem* s) : fileSys(s){ }

//execute function, will return value indicating success or appropriate error value
int MacroCommand::execute(std::string input) {
	int return_val = 0;
	std::vector<std::string> parsed = aps->parse(input);

	//iterate through commands
	for (int i = 0; i < commands.size(); ++i) {
		return_val = commands[i]->execute(parsed[i]);
		if (return_val != 0) break;
	}

	return return_val;
}

//display info command
void MacroCommand::displayInfo() {
	std::cout << "invoke rename by calling with rn <initialfile> <newfile> . invoke cat ds by calling cd <filename> [-a] [-d]" << std::endl;
}

//add command, will allow user to add new macro command
void MacroCommand::addCommand(AbstractCommand* abs) {
	commands.push_back(abs);
}

//setParseStrategy mutator
void MacroCommand::setParseStrategy(AbstractParsingStrategy* setAps) {
	this->aps = setAps;
}