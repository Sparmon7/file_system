// CatDsParsingStrategy.h
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Definitions for a concat + display parsing strategy.
// Will split the user input appropriatly and return the parsed value.
//

#include "CatDsParsingStrategy.h"

#include <iostream>
#include <sstream>

using namespace std;

std::vector<std::string> CatDsParsingStrategy::parse(std::string input) {
	std::vector<std::string> split_strings;
	std::vector<std::string> outputs;
	std::istringstream iss(input);
	std::string element;

	//split into seperate strings
	while (iss >> element) {
		split_strings.push_back(element);
	}
	const string append = "-a";

	//add to outputs
	if (split_strings.size() >= 2) {
		if (split_strings.at(1) == append) {
			//check if append and potentially a -d after
			if (split_strings.size() >= 3) {
				outputs.push_back(split_strings.at(0) + " " + split_strings.at(1));
				outputs.push_back(split_strings.at(0) + " " + split_strings.at(2));
			}
			else {
				//just append after
				outputs.push_back(split_strings.at(0) + " " + split_strings.at(1));
				outputs.push_back(split_strings.at(0) );
			}
			
		}
		else {
			//could be -d without append
			outputs.push_back(split_strings.at(0));
			outputs.push_back(split_strings.at(0) + " " + split_strings.at(1));
		}
		
	}
	else {
		//nothing after the file name
		outputs.push_back(split_strings.at(0));
		outputs.push_back(split_strings.at(0));
	}
	
	return outputs;
}