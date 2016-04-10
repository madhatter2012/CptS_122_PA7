/**************************************************************************************************
* Programmer: Cornell Michael Smith                                                              *
* Class: CptS 122; Lab Section 8                                                                 *
* Programming Assignment: PA 7                                                                   *
*                                                                                                *
* Date: 4/6/16                                                                                   *
*                                                                                                *
* Description: Write a C program that evaluates the equations provided below. The program        *
* must prompt the user for inputs to the equations and evaluate them based on the inputs. All    *
* variables on the right hand sides of the equations must be inputted by the user. All           *
* variables, except for the plaintext_character, encoded_character, variable a, shift, R1, R2,   *
* and R3 are floating-point values. The plaintext_character and encoded_character variables      *
* are characters, and the a, shift, R1, R2, and R3 variables are integers. The constants         *
* used in the equations must be defined as constant macros (#defined constants).                 *
*************************************************************************************************/



#include <iostream>
#include <string>

#include "Simpletron.h"

int main()

{
	Simpletron *app = new Simpletron();
	fstream * myFile = new fstream;
	myFile->open("Example1.sml");

	string line;
	int i = 0;
	while(!myFile->eof())
	{
		getline(*myFile, line);
		app->setInstrucs(line, i);
		i++;
	}

	int j = 0;
	while (!myFile->eof())
	{
		getline(*myFile, line);
		app->setMemoryArray(line, j);

	}

	app->displayInstrucs();
	app->displayMemoryArray();

	int accumulator = 0; //represents accumulator register
	int instructionCounter = 0;//tracks the location of the memory
	int operationCode = 0;//indicates oepration currently being performed
	int instructionRegister = 0; //accepts next instruction to be performed
	int operand = 0; //indicates memory location on which current instruction operates

	myFile->close();
	delete myFile;
	
	//system("PAUSE");
	return 0;
}