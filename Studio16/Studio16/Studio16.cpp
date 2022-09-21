// Studio16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\\SharedCode\TextFile.h"
#include <iostream>


using namespace std;

int main()
{
	AbstractFile* ethan = new TextFile("Ethan.txt");
	std::vector<char> test{'h', 'e', 'l', 'l', 'o'};
	std::vector<char> done{ 'g', 'o', 'o', 'd'};
	ethan->write(test);
	ethan->read();
	ethan->append(done);
	ethan->read();
	std::cout << ethan->getName() << std::endl;
	std::cout << ethan->getSize() << std::endl;

	return 0;
}


