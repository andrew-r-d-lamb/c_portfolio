/*************************************************************************************************

*Filename: calcWithArgs.c
*Authors: Andrew Lamb
*Last Modified: 24/12/2012
*Description:	Program takes user-input from cmd-line arguments and runs a simple calculator

*************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{	
	if (argc != 4) printf("Operators: +, -, x, / \nUsage: number1 operator number2\n");	//if user enters incorrect Parameters, prompt with how to use program
	
	else //do calculation (*argv[2] points to operator character. atoi(argv[1]) converts string to int so that they can be added together
	{
		printf ("\n");
		if (*argv[2]=='+') printf("%s %s %s = %d", argv[1], argv[2], argv[3], atoi(argv[1]) + atoi(argv[3]));	
		if (*argv[2]=='-') printf("%s %s %s = %d", argv[1], argv[2], argv[3], atoi(argv[1]) - atoi(argv[3]));	
		if (*argv[2]=='x') printf("%s %s %s = %d", argv[1], argv[2], argv[3], atoi(argv[1]) * atoi(argv[3]));
		if (*argv[2]=='/') 
		{
			if (atoi(argv[3]) == 0) 
			{
				printf("Cannot divide by 0.");
				return 1;
			}
			else printf("%s %s %s = %d", argv[1], argv[2], argv[3], atoi(argv[1]) / atoi(argv[3]));
		}
		printf ("\n");
	}
	
	return 0;
}