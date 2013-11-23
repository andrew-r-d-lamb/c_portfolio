/*************************************************************************************************

*Filename: pointers.c
*Authors: Andrew Lamb
*Last Modified: 24/12/2012
*Description:	Pointers practice, program takes input from user, modifies it slightly and outputs altered content

*************************************************************************************************/

#include <stdio.h>
#include <stdlib.h> //required for malloc function

int main(void)
{
	char *word;	//create pointer to char array named 'word'
	word = (char*) malloc(50);	//allocate array of 50 characters to word using malloc
	char *ptr;	//create pointer to char array named 'ptr'
	
	//check memory
	if (word == NULL)
	{
		printf("ERROR: There is insufficient memory to run program\n");
		return 2;
	}
	
	printf("Please Enter a Word:\n");	//request user input
	fgets(word, 50, stdin);	//get user input and store in char array word
	printf("You entered:\n%s\n", word);	//display contents of char array word

	ptr = &word[1];	//makes pointer ptr point to second character in word array
	ptr[1] = '_';	//modifies second element of ptr to be an '_'
	ptr[3] = '$';	//modifies fourth element of ptr to be a '$'

	printf("Your word has been changed by ptr to:\n%s\n", word);	//display new contents of char array word

	free(word);	//free word
	
	
	return 0;	//all OK
}