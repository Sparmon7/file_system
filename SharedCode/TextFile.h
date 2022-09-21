// TextFile.h
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Header file for a text file, a type of file that
// allows the user to store text.
//

#pragma once

#include"AbstractFile.h"

class TextFile : public AbstractFile {
public:
	virtual std::vector<char>  read() override;
	TextFile(TextFile*, std::string);
	virtual int  write(std::vector<char>) override;
	virtual int  append(std::vector<char>) override;
	virtual unsigned int  getSize() override;
	virtual std::string  getName() override;
	TextFile(std::string);
	virtual AbstractFile* clone(std::string) override;
	virtual void accept(AbstractFileVisitor*) override;
private:
	std::string name;
	std::vector<char> contents;
};