/*************************************************************************************************

*Filename: mallocPractice.c
*Authors: Andrew Lamb
*Last Modified: 24/12/2012
*Description:	Program allocates memory using malloc, gets input from user, prints output and memory address

*************************************************************************************************/

#include <stdio.h>
#include <stdlib.h> //required for malloc function
//#include <string.h> //include if str functions are needed

const int SENTENCE_LENGTH = 50; //define constant int of length 50

int main(void) //start main program
{
	char *memory;	//create pointer to character array - memory
	memory = (char*) malloc(SENTENCE_LENGTH);	//reserve memory for "memory"
	
	//check memory
	if (memory == NULL)
	{
		printf("ERROR: There is insufficient memory to run this program\n");
		return 2;
	}
	
	printf("Please Enter a sentence:\n");	//request user input
	fgets(memory, SENTENCE_LENGTH, stdin);	//store user input in memory array
	printf("The character array starting from memory location %u, contains:\n%s\n", memory, memory);	//display start of memory location %u,memory and contents %s,memory

	free(memory);	//free reserved memory

	return 0;	//all ok
}	//end program

/*!!!!!!!!NOTES!!!!!!!!!!
Contents of array are not printed on screen twice, because %u is an unsigned int and is giving us the starting location of the array memory
The %s, memory prints the contents of array memory on screen only once
*/