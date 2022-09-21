// AbstractFileVisitor.h
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Interface for a file visitor to be used in derived classes.
//

#pragma once

#include <vector>

//forward declarations
class TextFile;
class ImageFile;

class AbstractFileVisitor {
public:
	virtual void visit_TextFile(TextFile*) = 0;
	virtual void visit_ImageFile(ImageFile*) = 0;
};