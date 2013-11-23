/*************************************************************************************************

*Filename: fgetsExample.c
*Authors: Andrew Lamb
*Last Modified: 24/12/2012
*Description:	User enters a sentence, program prints sentence on screen
				NOTE: 	See when printing out that input from fgets 
						stores a newline character at end of string, so
						Correct? is placed on a newline. This does not happen
						with the input from the scanfExample.c program

*************************************************************************************************/

#include <stdio.h>

const int SENTENCE_LENGTH=100; //define constant

int main(void)
{
	char sentence[SENTENCE_LENGTH]; //define char variable

	printf("Enter a sentence: ");
	fgets(sentence, SENTENCE_LENGTH, stdin); //get sentence from user
	printf("You input: %s Correct?\n", sentence);
	
	return 0;	//all ok
}