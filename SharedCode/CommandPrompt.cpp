// CommandPrompt.cpp
// Authors: Garrett Ramsey, Ethan Weilheimer and Spencer Armon
// Purpose: Definitions for command prompt, which stores and runs
// a set list of commands.
//

#include "CommandPrompt.h"

#include <iostream>
#include <sstream>

using namespace std;

//setFileSystem mutator
void CommandPrompt::setFileSystem(AbstractFileSystem* name) {
	fileSys = name;
}

//setFileFactory mutator
void CommandPrompt::setFileFactory(AbstractFileFactory* name) {
	fileFac = name;
}

//add command function, allows user to add command to command prompt
int CommandPrompt::addCommand(string str, AbstractCommand* ptr) {
	//add command to map
	pair<map<string, AbstractCommand*>::iterator,bool> ret = mappy.insert(pair<string, AbstractCommand*>(str,ptr));

	//if successful, return success
	if (ret.second) {
		return static_cast<int>(retValues::success);
	}
	
	return static_cast<int>(retValues::notAdded);
}

//list commands function, will list all commands in map
void CommandPrompt::listCommands() {
	map<string, AbstractCommand*>::iterator it;
	string toCOUT = "";
	
	//print all commands
	for (it = mappy.begin(); it != mappy.end(); it++) {
		toCOUT += it->first + "\n";
	}
	cout << toCOUT << endl;
}

//prompt command, will prompt user to enter a command
string CommandPrompt::prompt() {
	
	cout << "$";
	string str;
	getline(cin, str);
	return str;
}

//run command, will continuously loop until user quits
int CommandPrompt::run() {
	//prompt user for command
	cout << "Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command." << endl;

	//loop until quit
	while (true) {
		string prompted = prompt();
		cout << endl;
		//if quit, exit with appropriate return value
		if (prompted == "q") {
			return static_cast<int>(retValues::quit);
		}

		//otherwise take userr input
		else {
			vector<string> inputs;
			stringstream s(prompted);
			string word;

			//add user input to vector
			while (s >> word) {
				inputs.push_back(word);
			}

			//if a command is entered
			if (inputs.size() > 1) {
				//if command is followed by help, display help for appropriate command
				if (inputs[0] == "help") {
					map<string, AbstractCommand*>::iterator it = mappy.find(inputs[1]);
					if (it != mappy.cend()) {
						try {
							it->second->displayInfo();
						}
						catch (...) {
							cout << "command failed" << endl;
						}
					}
					else {
						cout << "command does not exist" << endl;
					}
				}
				//otherwise call execute on the inputted function
				else {
					int index = static_cast<int>(prompted.find(" "));
					if (index != string::npos) {
						string ect = prompted.substr((index + 1));
						map<string, AbstractCommand*>::iterator it = mappy.find(inputs[0]);
						if (it != mappy.end()) {
							try {
								if (it->second->execute(ect) != 0) {
									cout << "command failed" << endl;
								}
							}
							catch (...) {
								cout << "command failed" << endl;
							}
						}
						else {
							cout << "command does not exist" << endl;
						}
					}
				}
			}

			//if only help is entered, display all commands
			else if (inputs.size() == 1) {
				if (inputs[0] == "help") {
					listCommands();
				}
				//otherwise call execute on appropriate command
				else {
					map<string, AbstractCommand*>::iterator it = mappy.find(prompted);
					if (it != mappy.end()) {
						try {
							if (it->second->execute("") != 0) {
								cout << "command failed" << endl;
							}
						}
						catch (...) {
							cout << "command failed" << endl;
						}
					}
					else {
						cout << "command does not exist" << endl;
					}
				}
			}
		}
	}
}