#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

#pragma once //this guards against g++ error "redefinition of class Output"

using std::string;
using std::cout;
using std::endl;
using std::ofstream;

class Output {
	bool logToFile = false;
	string logFilename;
	ofstream fileObj;
	string removeEndlines(string input, bool keepEndlines);
	string addColorsByType(string data, string type);
	public:
		void out(string data, string type, bool keepEndlines);
		void init(string file);
		void end();
};

void Output::init(string file) {
	logToFile = true;
	logFilename = file;
	fileObj.open(logFilename, std::ios::app); //appends to a current file and creates it if needed
}

void Output::out(string data, string type = "none", bool keepEndlines = false){
	if (!logToFile){
                cout << Output::addColorsByType(Output::removeEndlines(data, keepEndlines), type) << endl;
	} else {
		fileObj << Output::addColorsByType(Output::removeEndlines(data, keepEndlines), type) << endl;
	}
}

void Output::end(){
	fileObj.close();
	logToFile = false;
}

string Output::removeEndlines(string input = "", bool keepEndlines = false){
	if (!keepEndlines){ 
		for (int i = 0; i <= input.length(); i++){ //removes all \n's from the string
			while (input[i] == '\n'){ //loops a position because when the character is removed, the next one shifts into place
				input[i] = '\0'; // \0 is the null character
			}
		}
	}
	return input;
}

string Output::addColorsByType(string input = "", string type = "none"){
	if (type == "none"){return input;} //"none" is if you want to preserve input
	if (type == "info"){return "\e[1;46m[Info]\e[1;0m " + input;} //cyan background
	if (type == "error"){return "\e[1;41m\e[1;33m[Error]\e[1;0m " + input;} //red background, yellow text
	if (type == "warning"){return "\e[1;33m[Warning]\e[1;0m " + input;} //yellow text
	return input;
}
