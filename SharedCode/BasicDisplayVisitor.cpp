// BasicDisplayVisitor.cpp
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Definitions for display visitor, displaying each
// type of file in the correct format.
//

#include "BasicDisplayVisitor.h"

#include "TextFile.h"
#include "ImageFile.h"

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

//display function for an image file
void BasicDisplayVisitor::visit_ImageFile(ImageFile* im) {
	//get data and dimensions from image file
	vector<char> vec = im->read();
	int size = static_cast<int>(sqrt(vec.size()));
	
	//print out the correctly formatted data
	if (!vec.empty()) {
		for (int i = (size)-1; i >= 0; --i) {
			for (int j = 0; j < (size); ++j) {
				cout << vec[(size) * i + j];
			}
			cout << "\n";
		}
	}
 }

//display function for a text file
void BasicDisplayVisitor::visit_TextFile(TextFile* tx) {
	//get data from text file
	vector<char> vec = tx->read();

	//print data
	for (unsigned int iter = static_cast<int>(index::FIRST); iter < tx->getSize(); ++iter) {
		cout << vec[iter];
	}
	cout << endl;
 }
