/*************************************************************************************************

*Filename: threeGuesses.c
*Authors: Andrew Lamb
*Last Modified: 24/12/2012
*Description:	Program gives user 3 chances to guess correct word
				Program loops the correct answer multiple times if user answers incorrectly 3 times

*************************************************************************************************/

#include <stdio.h>
#include <string.h>	//required for string comparison

int main(void)
{
	const char SECRET[100] = "fail";
	char guess[100];
	int counter;
	printf("You only have 3 chances to guess the secret word:\n");
	for (counter = 0; (counter < 3) && (strcmp(SECRET, guess) != 0); counter++) //initialize counter, loop-continutation condition, increment counter
	{
		scanf("%99s",&guess);
		if (strcmp(SECRET, guess) == 0) //compare SECRET and guess to see if they are the same
		{
			printf("Well done. You got it right! You are very clever!!!!!!\n"); //if correct print this statement
		}
		else
		{
			printf("%s is not the secret word, please try again:\n"); //else if incorrect, print this statement
		}
	}
	for (counter = 0; (counter < 10000) && (strcmp(SECRET, guess) != 0); counter++) //initialize another counter, loop-continuation condition, increment counter
	{
		if (strcmp(SECRET, guess) != 0)
		{
			printf("FAIL, FAIL, FAIL, FAIL, FAIL, FAIL, FAIL, FAIL, FAIL, FAIL\n"); //if incorrect also print this statement
			printf("!!!!!!!!!!!!!!!!!!!!!!!!FAIL!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"); //if incorrect also print this statement
		}
	}
	
	return 0;	//all OK
}