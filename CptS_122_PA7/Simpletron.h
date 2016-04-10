#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::string;
using std::getline;

const int ARRAY_SIZE = 1000;

class Simpletron
{
private: 
	//private member variables
	string instructions[10];
	string memoryArray[ARRAY_SIZE];
	

public:
	
	//constructor
	Simpletron();

	//destructor
	~Simpletron();

	//setters
	void setInstrucs(string newInstrucs, int i);
	void setMemoryArray(string newMemory, int i);
	
	//getters
	string getInstrucs(int i);
	string getMemoryArray(int i);

	//displays
	void displayInstrucs();
	void displayMemoryArray();


	////reads the next SML function from memory
	//fetch();
	////determine operationCode and operand of the instruction
	//decode();
	////perform the correct operation
	//void execute(int * const memory, int * const pAccumulator, int * const pInstructionCounter,
	//	int * pOperationCode, int * pOperand, int * pInstructionRegister);

	//read();

	//write();

	//void load( int * const memLoad);

	//store();

	//add();

	//subtract();

	//divide();

	//multiply();

	//modulus();

	//exponentiation();

	//branch();

	//branchneg();
	//
	//branchzero();
	//halt();
};