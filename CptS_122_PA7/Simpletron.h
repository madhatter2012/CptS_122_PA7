#pragma once

//includes for file handling, strings, and pow
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

// const in definitions for execute() switch case statement
const int READ = 10;
const int WRITE = 11;
const int LOAD = 20;
const int STORE = 21;
const int ADD = 30;
const int SUBTRACT = 31;
const int DIVIDE = 32;
const int MULTIPLY = 33;
const int MODULUS = 34;
const int EXPO = 35;
const int BRANCH = 40;
const int BRANCHNEG = 41;
const int BRANCHZERO = 42;
const int HALT = 43;

//using std for reading, writing, endline, file handling, and pow
using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::string;
using std::getline;
using std::pow;

// Simpletron Class
class Simpletron
{
private: //private member variables
	
	int instructions[10]; //file instructions array
	int memoryArray[1000]; //memory array

	int accumulator = 0; //represents accumulator register
	int instructionCounter = 0; //tracks the location of the memory
	int operationCode = 0; //indicates operation currently being performed
	int instructionRegister = 0; //accepts next instruction to be performed
	int operand = 0; //indicates memory location on which current instruction operates
	
public: //public member functions

	//constructor
	Simpletron(int accumulator = 0, int instructionCounter = 0, int operationCode = 0,
		int instructionRegister = 0, int operand = 0);
	//Simpletron(int accumulator, int instructionCounter, int operationCode,
		//int instructionRegister, int operand);

	//destructor
	~Simpletron();

	//setters
	void setInstrucs(int newInstrucs, int i);
	void setMemoryArray(int newMemory, int j);
	void setInstructionCounter(int i);
	
	//getters
	int getInstrucs(int i);
	int getMemoryArray(int i);
	int getOperationCode(int i);
	int getInstructionCounter(int i);

	//displays
	void displayInstrucs();
	void displayMemoryArray();

	void fetch(); //reads the next SML function from memory
	
	void decode(); //determine operationCode and operand of the instruction
	
	void execute(); //perform the correct operation
};