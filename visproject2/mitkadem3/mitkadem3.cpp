// mitkadem3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "Compiler.h"
using namespace std;
int main(int argc, char* argv[]){
	fstream input_file;
	if (argc < 2) {
		std::cout << "please provide file name!\n";
		exit(0);
	}
	//open file
	input_file.open(argv[1], ios::in);
	if (!input_file) {
		throw "could not open file!";
	}
	//std::cout << "main program started" << endl;;
	Compiler cm;
	cm.read(input_file);
	

   // std::cout << "Hello World!\n"; 
}
