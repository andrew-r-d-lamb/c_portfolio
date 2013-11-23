/*************************************************************************************************

*Filename: colourfirstletter.c
*Authors: Andrew Lamb
*Last Modified: 24/12/2012
*Description:	Program asks user to input their favourite colour and prints back the first letter

*************************************************************************************************/

#include <stdio.h>

int main(void)
{
	char colour[50];
	printf("What's your favourite colour?\n");
	scanf("%49s", colour);
	printf("The First Letter of your Favourite Colour is: %c\n", colour[0]); /*Print first letter held in colour array*/

	return 0;	//all OK

}