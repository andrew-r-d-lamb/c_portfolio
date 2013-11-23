/*************************************************************************************************

*Filename: threeGuessesUsingFunction.c
*Authors: Andrew Lamb, Support for Function Use Received from James Coll
*Last Modified: 24/12/2012
*Description:	Program gives user 3 chances to guess correct word. Separate Function Used to receive User Input and modify array in Main
				Program loops the correct answer multiple times if user answers incorrectly 3 times

*************************************************************************************************/

#include <stdio.h>
#include <string.h>

void get_user_input (char *guess);

int main(void)
{
	const char SECRET[100] = "fail";
	char guess[100];
	int counter;
	printf("You only have 3 chances to guess the secret word:\n");
	for (counter = 0; (counter < 3) && (strcmp(SECRET, guess) != 0); counter++) //initialize counter, loop-continutation condition, increment counter
	{
		//scanf("%99s",&guess);
		get_user_input(guess);
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
	return 0;
}

/***************** FUNCTION TO RECEIVE USER INPUT ********************/
void get_user_input (char *guess)
{
	scanf("%99s", guess);
}