/*************************************************************************************************

*Filename: colouroverflow.c
*Authors: Andrew Lamb
*Last Modified: 24/12/2012
*Description:	Program is an example of bad coding practice causing an overflow in memory and 
				crashing program

*************************************************************************************************/

#include <stdio.h>

/*incorrect program see scanf section*/

int main(void)
{
	char colour[3];
	
	printf("What's your favourite colour?\n");
	scanf("%s",colour); /*should have "%2s" to prevent overflow - writing incorrectly to memory*/
	printf("The First Letter of your Favourite Colour is: %s\n",colour); 

	return 0;

}