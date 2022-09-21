// CatDsParsingStrategy.h
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Header file for a concat + display parsing strategy.
// Contains member function.
//

#pragma once

#include "..\..\\SharedCode\AbstractParsingStrategy.h"

class CatDsParsingStrategy : public AbstractParsingStrategy {
public:
	virtual std::vector<std::string> parse(std::string) override;
};