// mitkadem3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "Compiler.h"
using namespace std;
int main(int argc, char* argv[]){
	
	//check if file path is given
	if (argc < 2) {
		std::cout << "please provide file name!\n";
		exit(0);
	}
	ifstream input_file(argv[1]);
	//opens the file
	//input_file.open(argv[1], ios::in);
	//check if the file exists
	if (!input_file.is_open()) {
		throw "could not open file!";
	}
	//initializes a compiler, which will read the file and execute everything
	Compiler cm;
	cm.read(input_file);
	input_file.close();
}
