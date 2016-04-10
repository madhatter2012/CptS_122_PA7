#include "Simpletron.h"

//constructor
Simpletron::Simpletron()
{
	int x;

	for (x = 0; x < 10; x++)
	{
		instructions[x] = { "+00000" };
	}

	for (x = 0; x < 1000; x++)
	{
		memoryArray[x] = { "+00000" };
		
	}
}

//deconstructor
Simpletron::~Simpletron()
{
	delete instructions;
	delete memoryArray;
}

void Simpletron::setInstrucs(string newInstrucs, int i)
{
	instructions[i] = newInstrucs;
}

void Simpletron::setMemoryArray(string newMemory, int i)
{
	memoryArray[i]= newMemory;
}

string Simpletron::getInstrucs(int i)
{
	return instructions[i];
}

string Simpletron::getMemoryArray(int i)
{
	return memoryArray[i];
}

void Simpletron::displayInstrucs()
{
	int i; 
	if (instructions != nullptr)
	{
		for (i = 0; i < 10; i++)
		{
			cout << getInstrucs(i) << endl;
		}
	}
}

void Simpletron::displayMemoryArray()
{
	int i;
	if (memoryArray != nullptr)
	{
	for (i = 0; i < 1000; i++)
		{
			cout << getMemoryArray(i);
		}
	}
}


//
//
//void Simpletron::instructions()
//{
//	cout << "*** Welcome to Simpletron ***\n";
//	cout << "Program will read fom a file and run\n";
//
//}
//
//void load(int * const memLoad)
//{
//	int instruction;
//}
//
//void execute(int * const memory, int * const pAccumulator, int * const pInstructionCounter,
//	int * pOperationCode, int * pOperand, int * pInstructionRegister)
//{
//	int t;
//	bool fatal = false;
//}