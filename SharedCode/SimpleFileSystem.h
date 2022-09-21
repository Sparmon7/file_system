// SimpleFileSystem.h
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Header file for a file system, which allows the user
// to store and perform commands on files.
//

#pragma once

#include "AbstractFileSystem.h"

#include <map>
#include<set>

class SimpleFileSystem : public AbstractFileSystem {
public:
	virtual int addFile(std::string, AbstractFile*) override;
	virtual int deleteFile(std::string) override;
	virtual AbstractFile* openFile(std::string) override;
	virtual int closeFile(AbstractFile*) override;
	virtual std::set<std::string> getFileNames() override;
private:
	std::map<std::string, AbstractFile*> allFiles;
	std::set<AbstractFile*> openFiles;
};