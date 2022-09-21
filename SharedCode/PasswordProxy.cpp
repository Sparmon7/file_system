// PasswordProxy.cpp
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Definitions for a password proxy, which allows the
// user to password protect a file.
//

#include "PasswordProxy.h"

using namespace std;

//constructor
PasswordProxy::PasswordProxy(AbstractFile* absFile, string pass) : passFile(absFile), password(pass) { };

//destructor
PasswordProxy::~PasswordProxy() {
	delete this->passFile;
}

//password promt function, prompt user to enter password
string PasswordProxy::passwordPrompt() {
	string pass;
	cout << "Please enter the password: " << endl;
	getline(cin, pass);
	return pass;
}

//copy constructor
PasswordProxy::PasswordProxy(PasswordProxy* file, string newName) {
	 passFile = file->passFile->clone(newName);
	 password = file->password;

}

//password check, will perform password check and return boolean value
bool PasswordProxy::passwordCheck(string passCheck) {
	if (passCheck == password) return true;
	return false;
}

//read function, will check password and call read on file
vector<char> PasswordProxy::read() {
	vector<char> emptyVec;
	string pass = passwordPrompt();
	if (passwordCheck(pass)) return passFile->read();
	return emptyVec;
}

//write function, will check password and call write on file
int PasswordProxy::write(vector<char> writeVec) {
	string pass = passwordPrompt();
	//cout << pass;
	if (passwordCheck(pass)) return passFile->write(writeVec);
	return (int)return_values::WRITE_ERROR;
}

//append function, will check password and call append on file
int PasswordProxy::append(vector<char> appendVec) {
	string pass = passwordPrompt();
	if (passwordCheck(pass)) return passFile->append(appendVec);
	return (int)return_values::APPEND_ERROR;
}

//getSize accessor
unsigned int PasswordProxy::getSize() {
	return passFile->getSize();
}

//getName accessor
string PasswordProxy::getName() {
	return passFile->getName();
}

//accept function, will check password and call accept on file
void PasswordProxy::accept(AbstractFileVisitor* abv) {
	string pass = passwordPrompt();
	if (passwordCheck(pass)) { passFile->accept(abv); }
	else {
		cout << "Wrong password" << endl;
	}

}

//clone function
AbstractFile* PasswordProxy::clone(string newName) {
	return new PasswordProxy(this, newName);
}