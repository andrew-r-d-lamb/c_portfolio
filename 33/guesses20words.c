/*************************************************************************************************

*Filename: guesses20words.c
*Authors: Andrew Lamb
*Last Modified: 24/12/2012
*Description:	20 secret words in a text file. 
				User gets 3 guesses per secret word. 
				If user guesses correctly, next word is selected.

*************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	FILE *secretWord;	//Declare file pointer variable
	char secret[100];
	char guess[100];
	int counter = 0;
	char test[5];
	int count = 0;
	int temp;
	
	printf("There are 20 secret words.\nYou have 3 chances to guess each secret word.\nIf you guess one correctly you have 3 more guesses to guess the next one:\n");
		
		secretWord = fopen("secretword.txt", "r");	//open file for reading
		if (secretWord == NULL)	//check that file exists.  If file does not exist, end program.
		{
			printf("Cannot open secretWord for reading \n");
			exit(0);
		}
	
	while ((count < 20) && (strcmp(test, "done") != 0))
	{	
		fscanf(secretWord, "%s", &secret);	//write password from file to secret array. Line changes for each iteration of the while loop.
		
		for (counter = 0; (counter < 3) && (strcmp(test, "done") != 0)/*&& (strcmp(secret, guess) != 0)*/; counter++) //initialize counter, loop-continutation condition, increment counter
		{
			scanf("%99s",&guess);
			if (strcmp(secret, guess) == 0)	//if secret and guess are the same, do this:
			{
				printf("Well done. You guessed secret word number %d correctly\n", (temp = count + 1)); //if correct print this statement
				//printf("%s\n", test);
				strcpy(test, "done");	//Get out of for loop
				//printf("%s\n", test);
				if (count < 19) printf("Try guessing word %d:\n", (temp = count + 2));
				if (count == 19) printf("Congratulations, you guessed all the secret words\n");
			}
			else if (strcmp(secret, guess) != 0)	//if secret and guess are different, do this:
			{
				if (counter == 0) printf("%d:%s is not the secret word, you have two guesses remaining:\n", counter, guess);
				if (counter == 1) printf("%d:%s is not the secret word, you have one guess remaining:\n", counter, guess); //else if incorrect, print this statement
				if (counter == 2)
				{
					printf("%d:%s is not the secret word, you have no guesses remaining\n", counter, guess);
					//printf("%s\n", test);
					strcpy(test, "done");	//Get out of for loop
					//printf("%s\n", test);
				}
			}
		}
		
		if (strcmp(secret, guess) == 0) strcpy(test, "not");	//change value of test, so that while loop continues if person is guessing correctly
		//printf ("%d", count);
		count++;
	}
		
	fclose(secretWord);	//close file
	printf("Goodbye!\n");

	return 0;	//all OK
}