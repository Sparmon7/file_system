// Studio17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\\SharedCode\ImageFile.h"
#include "..\..\\SharedCode\TextFile.h"
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include<vector>

using namespace std;


int main()
{
	AbstractFileSystem* finder = new SimpleFileSystem();

	vector<char> board = { 'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', '3' };
	AbstractFile* image = new ImageFile("test");
	image->write(board);
	image->read();

	/*AbstractFile* text = new TextFile("text");
	AbstractFile* text2 = new TextFile("text2");

	finder->addFile("image.img", image);
	finder->addFile("text.txt", text);
	finder->addFile("text2.txt", text2);

	finder->createFile("text3.txt");
	finder->createFile("image2.img");

	finder->openFile("image.img");
	finder->openFile("image.img");

	finder->deleteFile("image.img");
	finder->closeFile(image);
	finder->deleteFile("image.img");*/

	return 0;
}

