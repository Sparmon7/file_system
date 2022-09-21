// RenameParsingStrategy.h
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Header file for a rename parsing strategy, which allows
// the user to rename a file by utilizing a macro command of copy and
// remove.
//

#pragma once

#include "AbstractParsingStrategy.h"

class RenameParsingStrategy : public AbstractParsingStrategy {
public:
	virtual std::vector<std::string> parse(std::string) override;
};