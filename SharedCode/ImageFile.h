// ImageFile.h
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Header file for an image file, a type of file that
// allows the user to store text formatted as an image.
//

#pragma once

#include"AbstractFile.h"

#include <vector>

class ImageFile : public AbstractFile {
public:
	virtual std::vector<char>  read() override;
	ImageFile(ImageFile*, std::string);
	virtual int  write(std::vector<char>) override;
	virtual int  append(std::vector<char>) override;
	virtual unsigned int  getSize() override;
	virtual std::string  getName() override;
	virtual AbstractFile* clone(std::string) override;
	ImageFile(std::string);
	virtual void accept(AbstractFileVisitor*) override;
private:
	std::vector<char> contents;
	std::string name;
	char size;
};