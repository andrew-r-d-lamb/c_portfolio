/*************************************************************************************************

*Filename: addsubtractintoarray.c
*Authors: Andrew Lamb
*Last Modified: 24/12/2012
*Description:	Program adds and subtracts 2 numbers entered by the user, stored in an array

*************************************************************************************************/

#include <stdio.h>

int main(void)
{
	int numbers[10],sum1[10],sub1[10];

	/*User Enters Numbers:*/
	printf("Enter 1st number you want to add and subtract:\n");
	scanf("%9d",&numbers[0]);
	printf("Enter 2nd number you want to add and subtract:\n");
	scanf("%9d",&numbers[1]);

	/*Addition Section*/
	sum1[1] = numbers[0] + numbers[1];
	printf("%9d + %9d = %9d\n",numbers[0],numbers[1],sum1[1]);

	/*Subtraction Section*/

	sub1[1] = numbers[0] - numbers[1];
	printf("%9d - %9d = %9d\n",numbers[0],numbers[1],sub1[1]);

	return 0;	//all OK
}