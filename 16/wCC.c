/*************************************************************************************************

*Filename: wCC.c
*Authors: Andrew Lamb
*Last Modified: 24/12/2012
*Description:	User inputs a word, program counts number of characters

*************************************************************************************************/

#include <stdio.h>

int main(void)
{
	char buffer[1000];
	int counter = 0;

	printf("Please Enter a word:\n");
	scanf("%999s", &buffer);
	while (buffer[counter] != '\0') //counter represents a number which changes each loop. buffer[counter] represents a particular letter in the array
	{
		counter++;	//counter = counter + 1
	}
		printf ("You entered: %s\n",buffer);
		printf ("Your word is: %d characters long\n",counter);

	return 0; //Everything OK
}