/*************************************************************************************************

*Filename: wordCountCharForLoop.c
*Authors: Andrew Lamb
*Last Modified: 24/12/2012
*Description:	User inputs a word, program counts characters using a for loop

*************************************************************************************************/

#include <stdio.h>

int main(void)
{
	char buffer[1000];
	int counter = 0;

	printf("Please Enter a Word:\n");
	scanf("%999s", &buffer); //user enters word
	for (counter = 0; buffer[counter] != '\0'; counter++); //counter = counter + 1 until last character in buffer is reached
	printf("You Entered: %s\n", buffer);
	printf("Your word is: %d characters long\n", counter);

	return 0;
}