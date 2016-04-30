#include "Simpletron.h"

//constructor
Simpletron::Simpletron(int accumulator, int instructionCounter, int operationCode,
	int instructionRegister, int operand)
{
	int x;
	int y;

	for (x = 0; x < 10; x++) //loop populating instructions array
	{
		instructions[x] = {+00000};
	}

	for (y = 0; y < 1000; y++) //loop populating memory array
	{
		memoryArray[y] = {+00000};
		
	}
}

//destructor
Simpletron::~Simpletron()
{
}

//setters
void Simpletron::setInstrucs(int newInstrucs, int i)
{
	instructions[i] = newInstrucs;
}

void Simpletron::setMemoryArray(int newMemory, int j)
{
	memoryArray[j]= newMemory;
}

void Simpletron::setInstructionCounter(int i)
{
	instructionCounter = i;
}


//getters
int Simpletron::getInstrucs(int i)
{
	return instructions[i];
}

int Simpletron::getMemoryArray(int j)
{
	return memoryArray[j];
}

int Simpletron::getOperationCode(int i)
{
	return operationCode;
}

int Simpletron::getInstructionCounter(int i)
{
	return instructionCounter;
}

//displays instruction array
void Simpletron::displayInstrucs()
{
	cout << "Populating instruction array..." << endl;
	int i; 
	if (instructions != nullptr)
	{
		for (i = 0; i < 10; i++)
		{
			cout << getInstrucs(i) << endl;
		}
	}
}

//displays memory Array
void Simpletron::displayMemoryArray()
{
	cout << "Populating memory array..." << endl;
	int j;
	for (j = 0; j < 1000; j++)
	{
		cout << getMemoryArray(j);
	}
	cout << endl;
}

//fetch - reads the next SML function from ***INSTRUCTIONS!***
void Simpletron::fetch()
{
	cout << "Fetching..." << endl;
	cout << endl << "instructionRegister is:" << instructionRegister << endl;
	cout << "instructionCounter is:" << instructionCounter << endl;
	cout << "instructions[0] is: " << instructions[0] << endl;
	cout << "instructions[instructionCounter] is: " << instructions[instructionCounter] << endl;
	instructionRegister = instructions[instructionCounter];
}

//decode - determine operationCode and operand of the instruction
void Simpletron::decode()
{
	cout << "decoding..." << endl;
operationCode = instructionRegister / 1000;
operand = instructionRegister % 1000;
}

//execute - perform the correct operation
void Simpletron::execute()
{
	cout << "executing..." << endl;
	switch (operationCode)
	{
	case READ: //read from keyboard into a specific memoryArray location
		cout << "Type an integer value: " << endl;
		cin >> memoryArray[operand];
		break;

	case WRITE: //write from a specific memoryArray location to screen
		cout << "Writing..." << endl;
		cout << memoryArray[operand] << endl;
		break;

	case LOAD: //load from a specific memoryArray location to accumulator
		cout << "Loading..." << endl;
		accumulator = memoryArray[operand];
		break;

	case STORE: //store from accumulator to memoryArray location
		cout << "Storing..." << endl;
		memoryArray[operand] = accumulator;
		break;

	case ADD: // add element from memoryArray to Accumulator (leaving result in accumulator)
		cout << "Adding..." << endl;
		accumulator += memoryArray[operand];
		break;

	case SUBTRACT: // subtract element from memoryArray to Accumulator (leaving result in accumulator)
		cout << "Subtracting..." << endl;
		accumulator -= memoryArray[operand];
		break;

	case DIVIDE: // divide element from memoryArray by Accumulator (leaving result in accumulator)
		cout << "Dividing..." << endl;
		accumulator /= memoryArray[operand];
		break;

	case MULTIPLY: // multiply element from memoryArray by Accumulator (leaving result in accumulator)
		cout << "Multiplying..." << endl;
		accumulator *= memoryArray[operand];
		break;
	
	case MODULUS: //modulus etc.
		cout << "Modulusing..." << endl;
		accumulator %= memoryArray[operand];
		break;

	case EXPO: //exponentiation etc.
		cout << "Expotentiating..." << endl;
		accumulator = pow(accumulator, memoryArray[operand]);
		break;

	case BRANCH: //branch to a specific location in memory
		cout << "Branching..." << endl;
		if (operationCode != 43)
			{
				instructionCounter = operand - 1;
			}
		break;

	case BRANCHNEG: //branch to a specific location in memory if acc is neg
		cout << "Brachneging..." << endl;
		if (operationCode != 43 && accumulator < 0)
			{
				instructionCounter = operand - 1;
			}
		break;

	case BRANCHZERO: //branch to a specific location in memory if acc is zero
		cout << "Branchzeroing..." << endl;
		if (operationCode != 43 && accumulator == 0)
			{
				instructionCounter = operand - 1;
			}
		break;

	case HALT: //ending program
	{
		cout << "Halting..." << endl;
		cout << "*** Simpletron execution terminated ***";
	}
	break;

	default: //for catching fatal errors
			cout << "*** Fatal Error ***";

Simpletron::instructionCounter++; //incrementing instructionCounter
	}
}
