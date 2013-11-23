/*************************************************************************************************

*Filename: guessTheWord.c
*Authors: Andrew Lamb
*Last Modified: 24/12/2012
*Description:	Program loops until user guesses correct word

*************************************************************************************************/

#include <stdio.h>
#include <string.h>	//required for string compare

int main(void)
{
	const char SECRET[100] = "blah";
	char guess[100];
	
	do
	{
		printf("Please guess the secret word:\n");
		scanf("%99s", &guess);
		if (strcmp(SECRET, guess) == 0)	//strcmp compares user guess with secret word
			{
			printf("Correct guess - well done!!!!!! You are very clever!!!!!!\n");
			}
		else
			{
			printf("Sorry %s is not the secret word\n");
			}
	} while (strcmp(SECRET, guess) != 0);
	
	return 0;
}