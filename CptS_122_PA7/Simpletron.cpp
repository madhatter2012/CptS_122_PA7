#include "Simpletron.h"

//constructor
Simpletron::Simpletron()
{
	int x;
	int y;
	int z;

	for (x = 0; x < 10; x++)
	{
		instructions[x] = { "+00000" };
	}

	for (x = 0; x < 10; x++)
	{
		for (y = 0; y < 10; y++)
		{
			for (z = 0; z < 10; z++)
			{
			memoryArray[x][y][z] = { "+00000" };
			}
		}
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

void Simpletron::setMemoryArray(string newMemory, int i, int j, int k)
{
	memoryArray[i][j][k] = newMemory;
}

string Simpletron::getInstrucs(int i)
{
	return instructions[i];
}

string Simpletron::getMemoryArray(int i, int j, int k)
{
	return memoryArray[i][j][k];
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
	int j;
	int k;
	if (memoryArray != nullptr)
	{
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 10; j++)
			{
				for (k = 0; k < 10; k++)
				{
					cout << getMemoryArray(i, j, k);
				}
			}
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