/*************************************************************************************************

*Filename: colour.c
*Authors: Andrew Lamb
*Last Modified: 24/12/2012
*Description:	Program asks user what their favourite colour is, stores it in an array
				and displays it back to the user

*************************************************************************************************/

#include <stdio.h>

int main(void)
{
	char colour[50];	//declare char array
	
	printf("What's your favourite colour?\n");
	scanf("%49s", colour);
	printf("You said: %s\n", colour);

	return 0;	//all ok

}