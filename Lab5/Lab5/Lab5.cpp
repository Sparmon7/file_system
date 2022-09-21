// Lab5.cpp
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Main cpp file. Creates a command prompt object and
// all necessary commands to make a functioning command prompt.
// Returns the value of run called on the command prompt object
//
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include "..\..\\SharedCode\SimpleFileFactory.h"
#include "..\..\\SharedCode\TouchCommand.h"
#include "..\..\\SharedCode\CommandPrompt.h"
#include "..\..\\SharedCode\RemoveCommand.h"
#include "..\..\\SharedCode\LSCommand.h"
#include "..\..\\SharedCode\CatCommand.h"
#include "..\..\\SharedCode\DisplayCommand.h"
#include "..\..\\SharedCode\CopyCommand.h"
#include "..\..\\SharedCode\MacroCommand.h"
#include "..\..\\SharedCode\RenameParsingStrategy.h"
#include "..\..\\SharedCode\ImageFile.h"
#include "..\..\\SharedCode\TextFile.h"
#include "CatDsParsingStrategy.h"
#include "ChmodCommand.h"

using namespace std;

int main()
{
	//all necessary systems, factories, parsing strategies and commands
	AbstractFileSystem* test = new SimpleFileSystem();
	AbstractFileFactory* fac = new SimpleFileFactory();
	AbstractParsingStrategy* rps = new RenameParsingStrategy();
	AbstractParsingStrategy* cdps = new CatDsParsingStrategy();
	AbstractCommand* touchy = new TouchCommand(test, fac);
	AbstractCommand* chmod = new ChmodCommand(test, fac);
	AbstractCommand* ls = new LSCommand(test);
	AbstractCommand* remove = new RemoveCommand(test);
	AbstractCommand* cat = new CatCommand(test);
	AbstractCommand* display = new DisplayCommand(test);
	AbstractCommand* copy = new CopyCommand(test);
	MacroCommand* rename = new MacroCommand(test);
	MacroCommand* catds = new MacroCommand(test);
	//add commands and set parsing strategies, create new command prompt
	CommandPrompt overall = CommandPrompt();
	catds->setParseStrategy(cdps);
	catds->addCommand(cat);
	catds->addCommand(display);
	rename->setParseStrategy(rps);
	rename->addCommand(copy);
	rename->addCommand(remove);
	overall.setFileSystem(test);
	overall.setFileFactory(fac);
	overall.addCommand("touch", touchy);
	overall.addCommand("rm", remove);
	overall.addCommand("ls", ls);
	overall.addCommand("cat", cat);
	overall.addCommand("ds", display);
	overall.addCommand("copy", copy);
	overall.addCommand("rn", rename);
	overall.addCommand("cd", catds);
	overall.addCommand("chmod", chmod);

	//return result of run called on command prompt
	return overall.run();
	//note that the commands will be deleted automatically after this line runs and the program closes, so no need to delete these command pointers
}


