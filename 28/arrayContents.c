/*************************************************************************************************

*Filename: arrayContents.c
*Authors: Andrew Lamb
*Last Modified: 24/12/2012
*Description:	Program stores user input in an array, displays memory location and contents

*************************************************************************************************/

#include <stdio.h>
//#include <stdlib.h>	//include if malloc required
//#include <string.h>	//include if string functions required

const int SENTENCE_LENGTH = 50;	//define constant int of length 50

int main(void)	//start program
{
	char memory[SENTENCE_LENGTH];	//define character array - memory
	
	printf("Please Enter a sentence:\n");	//request user input
	fgets(memory, SENTENCE_LENGTH, stdin);	//store user input in memory array
	printf("The contents of memory starting at location %u is:\n%s\n", memory, memory); //prints start location of array memory %u,memory and its contents %s,memory
	
	return 0;	//all ok
}	//end main program

/*!!!!!!!Notes!!!!!!!!!
As in program 27 which uses pointers and malloc, 
user input from fgets is stored in a location in memory which can be shown using %u, memory
*/