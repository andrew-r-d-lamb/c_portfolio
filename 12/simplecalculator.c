/*************************************************************************************************

*Filename: simplecalculator.c
*Authors: Andrew Lamb
*Last Modified: 24/12/2012
*Description:	Program is a simple calculator

*************************************************************************************************/

#include <stdio.h>
/*simplecalculator.c - Simple calculator
* Authors: Andrew Lamb
* Last Modified: 11-11-2012
*/

int main(void)
{
	int numbers[3];
	char operator;
	int operation;

	printf("Would you like to add, subtract, multiply or divide?\n Enter +, -, *, /:");
	do
	{
		operator = getchar();
	}
	while (operator == '\n');
	if (operator == '\n') printf("warning: char c contains a newline\n"); /*Check that operator != '\n'*/
		
	/*print what user wants to do*/
	if (operator == '+') printf("you said you would like to add\n");
	if (operator == '-') printf("you said you would like to subtract\n");
	if (operator == '*') printf("you said you would like to multiply\n");
	if (operator == '/') printf("you said you would like to divide\n");
		
	/*get numbers from user*/
	printf("enter first number:");
	scanf("%9d",&numbers[1]);
	printf("enter second number:");
	scanf("%9d",&numbers[2]);
		
	/*Do calculation based on what user has requested numbers entered*/
	if (operator == '+') /*Adding*/
	{
		operation = (numbers[1] + numbers[2]);
		printf("The total of %d and %d is: %d\n",numbers[1],numbers[2],operation);
	}
	else if (operator == '-') /*Subtracting*/
	{
		operation = (numbers[1] - numbers[2]);
		printf("%d minus %d is: %d\n",numbers[1],numbers[2],operation);
	}
	else if (operator == '*') /*Multiplying*/
	{
		operation = (numbers[1] * numbers[2]);
		printf("%d multiplied by %d is: %d\n",numbers[1],numbers[2],operation);
	}
	else if (operator == '/') /*Dividing*/
	{
		while (numbers[2] == 0)	//loop put in to stop program from crashing as it cannot divide by 0
		{
			printf("Cannot divide by 0. Please enter new number to divide by:");
			scanf("%9d",&numbers[2]);
		}
		operation = (numbers[1] / numbers[2]);
		printf("%d divided by %d is: %d\n",numbers[1],numbers[2],operation);
	}
	else
	{
		printf("Sorry, you seem to have entered an invalid parameter\nplease try running program again");
	}
	
	return 0;	//all OK
}