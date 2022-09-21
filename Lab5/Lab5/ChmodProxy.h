// ChmodProxy.h
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Header file for chmod utilizing the proxy pattern.
// Contains enum for return values
//

#pragma once

#include "..\..\\SharedCode\AbstractFile.h"

#include <sstream>

class ChmodProxy : public AbstractFile {
public:
	ChmodProxy(AbstractFile*, std::string);
	ChmodProxy(ChmodProxy*, std::string);
	virtual ~ChmodProxy();
	virtual std::vector<char> read() override;
	virtual int write(std::vector<char>) override;
	virtual int append(std::vector<char>) override;
	virtual unsigned int getSize() override;
	virtual std::string getName() override;
	virtual void accept(AbstractFileVisitor*) override;
	virtual AbstractFile* clone(std::string) override;
private:
	AbstractFile* passFile;
	bool writable;
};

//return values enum
enum struct return_valuess { WRITE_ERROR = 1, APPEND_ERROR = 2 };