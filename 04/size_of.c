/*************************************************************************************************

*Filename: size_of.c
*Authors: Andrew Lamb
*Last Modified: 24/12/2012
*Description:	Program displays the size of an int, char, float and double, and the size of 
				an int array with 3 elements
				a char array with 4 elements
				a float array with 5 elements and
				a double array with 6 elements

*************************************************************************************************/

#include <stdio.h>

int main (void)
{
	int three[3] = {5, 10, 30};	//declare int array and set values
	char four[4] = {'a', 'b', 'c', '\0'};	//declare char array and set values
	float five[5] = {1.1, 2.2, 3.3, 4.4, 5.5};	//declare float array and set values
	double six[6] = {1.111111, 2.2222222222, 3.33333333333, 4.444444, 5.5555555, 6.6666666};	//declare double array and set values
	
	/************** DISPLAY SIZE OF ELEMENTS/ARRAYS *************/
	printf("The size of an int is: %d\n", sizeof(int));
	printf("The size of int array three is: %d\n", sizeof(three));
	
	printf("The size of a char is: %d\n", sizeof(char));
	printf("The size of char array four is: %d\n", sizeof(four));
	
	printf("The size of a float is: %d\n", sizeof(float));
	printf("The size of float array five is: %d\n", sizeof(five));
	
	printf("The size of a double is: %d\n", sizeof(double));
	printf("The size of double array siz is: %d\n", sizeof(six));
	
	return 0;	//all OK
}