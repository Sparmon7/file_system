// MetadataDisplayVisitor.cpp
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Definitions for a metadata display visitor, which
// allows the user to view the metadata of a file.
//

#include "MetadataDisplayVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"

using namespace std;

//display metadata for text file
void MetadataDisplayVisitor::visit_TextFile(TextFile* tx) {
	type = "text";
	size = tx->getSize();
	name = tx->getName();
	cout << name << " " << type << " " << size << endl;
}

//display metadata for image file
void MetadataDisplayVisitor::visit_ImageFile(ImageFile* im) {
	type = "image";
	size = im->getSize();
	name = im->getName();

	cout << name << " " << type << " "<< size << endl;

}
