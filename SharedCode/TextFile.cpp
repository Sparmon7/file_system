// TextFile.cpp
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Definitions for a text file, a type of file that
// allows the user to store text.
//

#include "TextFile.h"

using namespace std;

//constructor
TextFile::TextFile(std::string nam) : name(nam) { }

//copy constructor
TextFile::TextFile(TextFile* file, string newName) {
	name = newName + ".txt";
	contents = file->read();
}

//accept function, will call visit on text file
void TextFile::accept(AbstractFileVisitor* vi) {
	vi->visit_TextFile(this);
}

//read function, will return contents
vector<char> TextFile::read() {
	return contents;
}

//write function, will write to text file
int TextFile::write(std::vector<char> input) {
	contents = input;
	return static_cast<int>(outcomes::SUCCESS);
}

//append function, will append to end of text file
int TextFile::append(vector<char> v) {
	for (unsigned int i = static_cast<int>(index::FIRST); i < v.size(); ++i) {
		contents.push_back(v[i]);
	}

	return static_cast<int>(outcomes::SUCCESS);
}

//getSize accessor
unsigned int TextFile::getSize() {
	return  static_cast<unsigned int>(contents.size());
}

//getName accessor
std::string  TextFile::getName() {
	return this->name;
}

//clone function
AbstractFile* TextFile::clone(string newName) {
	return new TextFile(this, newName);
}