/*************************************************************************************************

*Filename: addandsubtracttwonumbers.c
*Authors: Andrew Lamb
*Last Modified: 24/12/2012
*Description:	Program adds and subtracts 2 numbers entered by the user

*************************************************************************************************/

#include <stdio.h>

int main(void)
{
	int number1,number2,sum1,sub1;

	/*User Enters Numbers:*/
	printf("Enter 1st number you want to add and subtract:\n");
	scanf("%9d",&number1);
	printf("Enter 2nd number you want to add and subtract:\n");
	scanf("%9d",&number2);

	/*Addition Section*/
	sum1 = number1 + number2;
	printf("%9d + %9d = %9d\n",number1,number2,sum1);

	/*Subtraction Section*/
	sub1 = number1 - number2;
	printf("%9d - %9d = %9d\n",number1,number2,sub1);

	return 0;
}