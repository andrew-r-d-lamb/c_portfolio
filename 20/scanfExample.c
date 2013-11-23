/*************************************************************************************************

*Filename: scanfExample.c
*Authors: Andrew Lamb
*Last Modified: 24/12/2012
*Description:	User enters a sentence, program prints sentence on screen
				NOTE: 	See when printing out that information input from scanf
						prints out all on one line, unlike the fgetsExample.c program

*************************************************************************************************/

#include <stdio.h>
int main(void)
{
char word[100];

	printf("Enter a word: ");
	scanf("%99s",word); //get word from user. fgets will add remaining blank characters in array to end of the sentence
	printf("You input: %s Correct?\n", word);
	
	return 0;	//all OK
}