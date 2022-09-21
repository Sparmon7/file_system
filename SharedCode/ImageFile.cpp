// ImageFile.cpp
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Definitions for an image file, a type of file that
// allows the user to store text formatted as an image.
//

#include "ImageFile.h"

#include <sstream>

using namespace std;

//constructor
ImageFile::ImageFile(std::string nam) : name(nam), size('0') { }

//copy constructor
ImageFile::ImageFile(ImageFile* file, string newName) {
	name = newName + ".img";
	contents = file->read();
	size = file->getSize();
}

//read function, will return contents
vector<char>  ImageFile::read() {
	return contents;
}

//accept function, will call visit on image file
void ImageFile::accept(AbstractFileVisitor * vi) {
	vi->visit_ImageFile(this);
}

//write function, will return value indicating success or appropriate error val
int ImageFile::write(std::vector<char> input)  {
	//return error is cannot write
	if (input[input.size() - 1] > '9' || input[input.size() - 1] < '0') {
		return static_cast<int>(outcomes::ERROR_WRITING);
	}
	size = input[input.size() - 1];

	//check for size mismatch
	int si = size - '0';
	si = si * si;
	if (input.size() != (si + 1)) {
		return static_cast<int>(outcomes::SIZE_MISMATCH);
	}

	//write to file
	for (int i = 0; i < input.size() - 1; ++i) {
		if (input[i] == 'X' || input[i] == ' ') {
			contents.push_back(input[i]);
		}
		else {
			contents.clear();
			size = '0';
			return static_cast<int>(outcomes::ERROR_WRITING);
		}
	}
	return static_cast<int>(outcomes::SUCCESS);
}

//appent function for image file, not supported
int ImageFile::append(vector<char> v) {
	cerr << "The append function is not supported for this filetype" << endl;
	return static_cast<int>(outcomes::NA);
}

//getSize accessor
unsigned int ImageFile::getSize() {
	return static_cast<int>(contents.size());
}

//clone function
AbstractFile * ImageFile::clone(string newName) {
	return new ImageFile(this, newName);
}

//getName accessor
std::string  ImageFile::getName() {
	return this->name;
}