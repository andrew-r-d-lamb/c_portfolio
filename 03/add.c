/*************************************************************************************************

*Filename: add.c
*Authors: Andrew Lamb
*Last Modified: 24/12/2012
*Description:	Program assigns values to two variables - one and two, assigns the sum of those to 
				another variable - three, and displays the contents of all three.

*************************************************************************************************/

#include <stdio.h>

int main(void)
{
	int one = 2; /*create a variable one which is 2*/
	int two = 3; /*create a variable two which is 3*/
	int three = one + two; /*add variables named one and two*/
	
	printf("the value stored in one is: %d\n",one); /*show variable one on screen*/
	printf("the value stored in two is: %d\n",two); /*show variable two on screen*/
	printf("the sum of values one and two is: %d\n", three); /*show variable three on screen*/
	
	return 0;
}