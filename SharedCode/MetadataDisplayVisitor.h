// MetadataDisplayVisitor.h
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Header file for a metadata display visitor, which
// allows the user to view the metadata of a file.
//

#pragma once
#include "AbstractFileVisitor.h"

#include <string>
#include <vector>

class MetadataDisplayVisitor : public AbstractFileVisitor {
public:
	virtual void visit_TextFile(TextFile*);
	virtual void visit_ImageFile(ImageFile*) ;
	std::string name;
	unsigned int size;
	std::string type;
};
