/*************************************************************************************************

*Filename: largestnumberfromthree.c
*Authors: Andrew Lamb
*Last Modified: 24/12/2012
*Description:	User inputs three numbers and program outputs largest number

*************************************************************************************************/

#include <stdio.h>

int main(void)
{
	int numbers[3];

	printf("Enter First Number:\n");
	scanf("%9d",&numbers[0]);
	printf("Enter Second Number:\n");
	scanf("%9d",&numbers[1]);
	printf("Enter Third Number:\n");
	scanf("%9d",&numbers[2]);

	if ((numbers[0] > numbers[1]) && (numbers[0] > numbers[2])) /*Check if numbers[0] is largest number*/
	{
		printf("the largest number you entered is: %d\n",numbers[0]);
	}
	else if ((numbers[1] > numbers[0]) && (numbers[1] > numbers[2])) /*Check if numbers[1] is largest number*/
	{
		printf("the largest number you entered is: %d\n",numbers[1]);
	}
	else if ((numbers[2] > numbers[0]) && (numbers[2] > numbers[1])) /*Check if numbers[2] is largest number*/
	{
		printf("the largest number you entered is: %d\n",numbers[2]);
	}
	else	/*if none of the numbers entered is larger than any other print the following*/
	{
		printf("some of the numbers you entered are equal\n");
	}
	
	return 0;	//all OK
}