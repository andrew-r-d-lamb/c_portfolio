/*************************************************************************************************

*Filename: calcWithArgsSscanf.c
*Authors: Andrew Lamb
*Last Modified: 24/12/2012
*Description:	Program takes user-input from cmd-line arguments and runs a simple calculator
				Uses Sscanf to scan characters from arguments into integer array

*************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{	
	int numbers[4];
	
	if (argc != 4) printf("Operators: +, -, x, / \nUsage: number1 operator number2\n");	//if user enters incorrect Parameters, prompt with how to use program
	
	else //do calculation (*argv[2] points to operator character. sscanf writes integer from argv string to int numbers array
	{
		printf ("\n");
		sscanf(argv[1], "%d", &numbers[1]);
		sscanf(argv[3], "%d", &numbers[3]);
		
		switch (*argv[2])
		{
			case '+':
				printf("%d %s %d = %d", numbers[1], argv[2], numbers[3], numbers[1] + numbers[3]);
				break;
			case '-':
				printf("%d %s %d = %d", numbers[1], argv[2], numbers[3], numbers[1] - numbers[3]);
				break;
			case 'x':
				printf("%d %s %d = %d", numbers[1], argv[2], numbers[3], numbers[1] * numbers[3]);
				break;
			case '/':
				if (numbers[3] == 0)
				{
					printf("Cannot divide by 0.");
					break;
				}
				else
				{
					printf("%d %s %d = %d", numbers[1], argv[2], numbers[3], numbers[1] / numbers[3]);
					break;
				}
		}
		printf ("\n");
	}
	
	return 0;
}