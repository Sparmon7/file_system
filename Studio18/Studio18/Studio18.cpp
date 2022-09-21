// Studio18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include "..\..\\SharedCode\SimpleFileFactory.h"
#include "..\..\\SharedCode\TextFile.h"
#include <vector>


using namespace std;

int main()
{
	AbstractFileSystem* test = new SimpleFileSystem();
	AbstractFileFactory* fact = new SimpleFileFactory();
	test->addFile("image.img", fact->createFile("image.img"));
	test->addFile("text.txt", fact->createFile("text.txt"));
	std::vector<char> best = { 'h','p','d'};
	AbstractFile* name = test->openFile("text.txt");
	name->write(best);
	name->read();
	return 0;
}
