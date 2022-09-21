// BasicDisplayVisitor.h
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Header file for a display visitor containing member functions.
//

#pragma once

#include "AbstractFileVisitor.h"

class BasicDisplayVisitor : public AbstractFileVisitor {
public: 
	virtual void visit_ImageFile(ImageFile*);
	virtual void visit_TextFile(TextFile*);
};
