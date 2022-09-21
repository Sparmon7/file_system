// AbstractParsingStrategy.h
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Interface for a parsing strategy to be used in derived
// classes.
//

#pragma once

#include <vector>
#include <string>

class AbstractParsingStrategy {
public:
	virtual std::vector<std::string> parse(std::string) = 0;
};