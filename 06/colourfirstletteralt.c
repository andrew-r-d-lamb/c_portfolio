/*************************************************************************************************

*Filename: colourfirstletter.c
*Authors: Andrew Lamb
*Last Modified: 24/12/2012
*Description:	Program asks user to input their favourite colour and prints back the first letter
				Program changes second letter of array colour to '\0' to do this

*************************************************************************************************/

#include <stdio.h>

int main(void)
{
	char colour[50];
	
	printf("What's your favourite colour?\n");
	scanf("%49s",colour);
	colour[1] = '\0';	//set second element in array colour to '\0'

	printf("The First Letter of your Favourite Colour is: %s\n", colour); /*Print first letter held in colour array*/

	return 0;	//all OK

}