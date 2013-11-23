/*************************************************************************************************

*Filename: unsignedint.c
*Authors: Andrew Lamb
*Last Modified: 24/12/2012
*Description:	Program is an example of what happens when 
				you try to put a negative value into an unsigned integer

*************************************************************************************************/

#include <stdio.h>

int main(void)
{
	unsigned int t = 1;	//create unsigned int and initialise to value 1

	printf("Unsigned int t has a value of:%u\n",t); //display unsigned int value
	t = t - 2;
	printf("t minus 2 =:%u\n",t); //large number should be displayed because unsigned int cannot hold negative values

	return 0;	//all Ok
}