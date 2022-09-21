// Studio20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\\SharedCode\AbstractFile.h"
#include "..\..\\SharedCode\PasswordProxy.h"
#include "..\..\\SharedCode\TextFile.h"
#include <vector>

using namespace std;

int main()
{
	string password = "password";
	vector<char> writeVec = { 'h', 'e', 'l', 'l', 'o' };
	int returnVal = 0;
	AbstractFile* text = new TextFile("text.txt");
	PasswordProxy pass(text, password);
	returnVal = pass.write(writeVec);
	pass.read();

	return returnVal;
}

