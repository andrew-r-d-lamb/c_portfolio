/*************************************************************************************************

*Filename: pp11.c
*Authors: Andrew Lamb
*Last Modified: 24/12/2012
*Description:	Program gets word from user using scanf and character from user using getchar()
				do-while loop used to remove '\n' character from getchar()

*************************************************************************************************/

#include <stdio.h>

int main(void)
{
	char word[10];
	char c;
	
	printf("enter a word: ");
	scanf("%9s", word);
	printf("enter any character: ");
	do
	{
	c = getchar();
	} while (c == '\n');
	if (c == '\n') printf("warning: char c contains a newline\n");
	
	printf("you entered: word: %s, char: %c\n", word, c);
	
	return 0;	//all ok
}