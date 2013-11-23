/*************************************************************************************************

*Filename: simplecalculatorloop.c
*Authors: Andrew Lamb
*Last Modified: 24/12/2012
*Description:	Program is a simple calculator that loops until user enters q to quit

*************************************************************************************************/

#include <stdio.h>

int main(void)
{
	int numbers[3];
	char operator;
	int operation;
	do
	{
		operator = '\n'; /*??????????Restart getchar in loop - THIS SEEMS LIKE A BIT OF A HACK?????????*/
		printf("Add(+), Subtract(-), Multiply(*), Divide(/), or Quit(q):");
		do
		{
			operator = getchar();
		}
		while (operator == '\n');

		if (operator == '\n') printf("warning: char c contains a newline\n"); /*Check that operator != '\n'*/
		
		/*print what user wants to do*/
		if (operator == '+') printf("\nyou said you would like to add:\n");
		if (operator == '-') printf("\nyou said you would like to subtract:\n");
		if (operator == '*') printf("\nyou said you would like to multiply:\n");
		if (operator == '/') printf("\nyou said you would like to divide:\n");
			
		/*get numbers from user*/
		if	((operator == '+') || (operator == '-') || (operator == '*') || (operator == '/'))
		{	
			printf("enter first number:");
			scanf("%9d",&numbers[1]);
			printf("enter second number:");
			scanf("%9d",&numbers[2]);
		}	
			/*Do calculation based on what user has requested numbers entered*/
		if (operator == '+') /*Adding*/
		{
			operation = (numbers[1] + numbers[2]);
			printf("%d\n+\n%d\n=\n%d\n\n",numbers[1],numbers[2],operation);
		}
		else if (operator == '-') /*Subtracting*/
		{
			operation = (numbers[1] - numbers[2]);
			printf("%d\n-\n%d\n=\n%d\n\n",numbers[1],numbers[2],operation);
		}
		else if (operator == '*') /*Multiplying*/
		{
			operation = (numbers[1] * numbers[2]);
			printf("%d\n*\n%d\n=\n%d\n\n",numbers[1],numbers[2],operation);
		}
		else if (operator == '/') /*Dividing*/
		{
			while (numbers[2] == 0)	//loop put in to stop program from crashing as it cannot divide by 0
			{
				printf("Cannot divide by 0. Please enter new number to divide by:");
				scanf("%9d",&numbers[2]);
			}
			operation = (numbers[1] / numbers[2]);
			printf("%d\n/\n%d\n=\n%d\n\n",numbers[1],numbers[2],operation);
		}

	} while (operator != 'q');
	
	return 0;	//all OK
}