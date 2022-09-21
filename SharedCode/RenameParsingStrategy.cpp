// RenameParsingStrategy.cpp
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Defintions for a rename parsing strategy, which allows
// the user to rename a file by utilizing a macro command of copy and
// remove.
//

#include "RenameParsingStrategy.h"

#include <iostream>
#include <sstream>

//parse function for rename
std::vector<std::string> RenameParsingStrategy::parse(std::string input) {
	std::vector<std::string> split_strings;
	std::vector<std::string> outputs;
	std::istringstream iss(input);
	std::string element;

	//split into seperate strings
	while (iss >> element) {
		split_strings.push_back(element);
	}

	//add to outpus
	outputs.push_back(split_strings.at(0) + " " + split_strings.at(1));
	outputs.push_back(split_strings.at(0));

	return outputs;
}