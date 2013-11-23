/*************************************************************************************************

*Filename: countEachLetterSimple.c
*Authors: Andrew Lamb
*Last Modified: 24/12/2012
*Description:	Program takes sentence from user and counts number of each letter of alphabet entered in sentence
				NOTE: Program only counts lower-case letters

*************************************************************************************************/

#include <stdio.h>

int main (void)
{
	char alphabet[27]= {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '\0'};	//Create char array and initialise values to the letters of the alphabet
	char words[100];
	int i = 0;	//counter
	int j = 0; 	//counter
	int sum;
	
	printf("\nPlease Enter a sentence:\n");
	fgets(words, 100, stdin);
	
	printf("\nYour sentence contains: \n");
	for (i = 0; alphabet[i] != '\0'; i++)	//loop through alphabet letters one at a time
	{
		sum = 0;							
		for (j = 0; words[j] != '\0'; j++)	//loop through words sentence one at a time and compare to alphabet letter
		{
			if (alphabet[i] == words[j])	
			{
				sum = sum + 1;				//if equal, add to sum
			}
		}
		printf("%c: %d\n", alphabet[i], sum);	//output sum for each letter
	}

	return 0;	//all OK
}	

