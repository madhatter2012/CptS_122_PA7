/**************************************************************************************************
* Programmer: Cornell Michael Smith                                                              *
* Class: CptS 122; Lab Section 8                                                                 *
* Programming Assignment: PA 7                                                                   *
*                                                                                                *
* Date: 4/6/16                                                                                   *
*                                                                                                *
* Description:																					 *
*************************************************************************************************/



#include <iostream>
#include <string>

#include "Simpletron.h"

int main() //main start

{
	// variables
	char line[10];
	int intInstrucs;
	int i = 0;
	int j = 0;
	//int k = 0;

	Simpletron app; //instantiating simpletron object
	fstream myFile; // filestream object
	myFile.open("Example1.sml"); //opening file for processing
	

	// while loop reading from file into intructions array
	while(!myFile.eof())
	{
		myFile.getline(line, 10);
		intInstrucs = atoi(line);
		app.setInstrucs(intInstrucs, i);
		i++;
	}

	//displaying Insructions and Memory Arrays
	app.displayInstrucs();
	app.displayMemoryArray();

	do // do while loop for fetch, decode, and execute
	{

		app.fetch();

		app.decode();

		app.execute();

		j++;

		app.setInstructionCounter(j);

	} while (app.getOperationCode(i)!= 43);
	
	myFile.close(); //closing file
	
	return 0;

} //main end