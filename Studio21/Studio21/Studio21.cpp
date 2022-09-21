// Studio21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include "..\..\\SharedCode\SimpleFileFactory.h"
#include "..\..\\SharedCode\TouchCommand.h"
#include "..\..\\SharedCode\CommandPrompt.h"

int main()
{
	AbstractFileSystem* test = new SimpleFileSystem();
	AbstractFileFactory* fac= new SimpleFileFactory();
	AbstractCommand* touchy = new TouchCommand(test, fac);
	CommandPrompt overall = CommandPrompt();
	overall.setFileSystem(test);
	overall.setFileFactory(fac);
	overall.addCommand("touch", touchy);
	return overall.run();
}

