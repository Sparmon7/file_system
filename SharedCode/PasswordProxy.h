// PasswordProxy.h
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Header file for a password proxy, which allows the
// user to password protect a file.
//

#pragma once

#include "AbstractFile.h"

class PasswordProxy : public AbstractFile {
public:
	PasswordProxy(AbstractFile*, std::string);
	PasswordProxy(PasswordProxy*, std::string);
	virtual ~PasswordProxy();
	virtual std::vector<char> read() override;
	virtual int write(std::vector<char>) override;
	virtual int append(std::vector<char>) override;
	virtual unsigned int getSize() override;
	virtual std::string getName() override;
	virtual void accept(AbstractFileVisitor*) override;
	virtual AbstractFile* clone(std::string) override;
protected:
	std::string passwordPrompt();
	bool passwordCheck(std::string);
private:
	AbstractFile* passFile;
	std::string password;
};

enum struct return_values { WRITE_ERROR = 1, APPEND_ERROR = 2 };