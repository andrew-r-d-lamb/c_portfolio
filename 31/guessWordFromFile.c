/*************************************************************************************************

*Filename: guessWordFromFile.c
*Authors: Andrew Lamb
*Last Modified: 24/12/2012
*Description:	Secret word stored in file. user has three attempts to guess the word
				Program loops the correct answer multiple times if user answers incorrectly 3 times

*************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	FILE *secretWord;	//Declare file pointer variable
	char secret[100];
	char guess[100];
	int counter;
	printf("You only have 3 chances to guess the secret word:\n");
	
	secretWord = fopen("secretword.txt", "r");	//open file for reading
	if (secretWord == NULL)	//check that file exists
	{
		printf("Cannot open secretWord for reading \n");
		exit(0);
	}
	fscanf(secretWord, "%s", &secret);	//write file contents to secret array
	//printf("%s\n", guess);
	
	fclose(secretWord);	//close file
	
	for (counter = 0; (counter < 3) && (strcmp(secret, guess) != 0); counter++) //initialize counter, loop-continutation condition, increment counter
	{
		scanf("%99s",&guess);
		if (strcmp(secret, guess) == 0) //compare secret and guess to see if they are the same
		{
			printf("Well done. You got it right! You are very clever!!!!!!\n"); //if correct print this statement
		}
		else
		{
			printf("%s is not the secret word, please try again:\n"); //else if incorrect, print this statement
		}
	}
	for (counter = 0; (counter < 10000) && (strcmp(secret, guess) != 0); counter++) //initialize another counter, loop-continuation condition, increment counter
	{
		if (strcmp(secret, guess) != 0)
		{
			printf("FAIL, FAIL, FAIL, FAIL, FAIL, FAIL, FAIL, FAIL, FAIL, FAIL\n"); //if incorrect also print this statement
			printf("!!!!!!!!!!!!!!!!!!!!!!!!FAIL!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"); //if incorrect also print this statement
		}
	}
	
	return 0;	//all OK
}