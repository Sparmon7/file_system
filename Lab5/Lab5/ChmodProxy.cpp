// ChmodProxy.cpp
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Definitions for chmod utilizing the proxy pattern.
//

#include "ChmodProxy.h"

using namespace std;

//constructor, determines if file should be writable
ChmodProxy::ChmodProxy(AbstractFile* absFile, string pass) : passFile(absFile), writable(true) { 
	vector<string> inputs;
	stringstream s(pass);
	string word;
	
	while (s >> word) {
		inputs.push_back(word);
	}
	if (inputs[1] == "+") {
		writable = true;
	}
	if (inputs[1] == "-") {
		writable = false;
	}
};

//destructor
ChmodProxy::~ChmodProxy() {
	delete this->passFile;
}

//copy constructor
ChmodProxy::ChmodProxy(ChmodProxy* file, string newName) {
	passFile = file->passFile->clone(newName);
	vector<string> inputs;
	stringstream s(newName);
	string word;

	while (s >> word) {
		inputs.push_back(word);
	}
	if (inputs[1] == "+") {
		writable = true;
	}
	if (inputs[1] == "-") {
		writable = false;
	}

}

//read function
vector<char> ChmodProxy::read() {
	return passFile->read();
}

//write function
int ChmodProxy::write(vector<char> writeVec) {
	if (writable) {
		return passFile->write(writeVec);
	}
	cout << "Cannot write to this file" << endl;
	return (int)return_valuess::WRITE_ERROR;
}

//append function
int ChmodProxy::append(vector<char> appendVec) {
	if (writable) {
		return passFile->append(appendVec);
	}
	cout << "Cannot write to this file" << endl;
	return (int)return_valuess::APPEND_ERROR;
}

//getSize accessor
unsigned int ChmodProxy::getSize() {
	return passFile->getSize();
}

//getName accessor
string ChmodProxy::getName() {
	return passFile->getName();
}

//accept function
void ChmodProxy::accept(AbstractFileVisitor* abv) {
	passFile->accept(abv);
}

//clone function
AbstractFile* ChmodProxy::clone(string newName) {
	return new ChmodProxy(this, newName);
}