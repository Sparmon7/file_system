// Studio19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include "..\..\\SharedCode\SimpleFileFactory.h"
#include "..\..\\SharedCode\BasicDisplayVisitor.h"
#include "..\..\\SharedCode\MetadataDisplayVisitor.h"
#include <vector>


using namespace std;
int main()
{
	AbstractFileSystem* test = new SimpleFileSystem();
	AbstractFileFactory* fact = new SimpleFileFactory();
	test->addFile("image.img", fact->createFile("image.img"));
	test->addFile("text.txt", fact->createFile("text.txt"));
	std::vector<char> best = { 'h','p','d' };
	AbstractFile* name = test->openFile("text.txt");
	name->write(best);
	AbstractFileVisitor* abvis = new BasicDisplayVisitor();
	AbstractFileVisitor* abvis2 = new MetadataDisplayVisitor();
	name->accept(abvis);

	std::vector<char> imvec = { 'X','X',' ','X','2'};
	AbstractFile* name2 =  test->openFile("image.img");
	name2->write(imvec);

	cout << name2->read().size() << endl;
	name2->accept(abvis2);
	


	return 0;
}
