/**************************************************************************************************

*Filename: checkbrackets.c
*Authors: Andrew Lamb
*Last Modified: 03/12/2012
*Description: Program counts number of brackets ()[]{} and informs user if there are a different number of left and right brackets

**************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>	//required for "exit" function

int main(int argc, char *argv[])
{
	FILE *csource;
	char filename[100];
	int checkbrackets;
	int countLeftBrace = 0, countRightBrace = 0, countLeftSquare = 0, countRightSquare = 0, countLeftCurly = 0, countRightCurly = 0;
	
	if (argc != 2) printf("\nProgram will count left and right brackets ()[]{}\nand tell you if there are a different number of them\nCorrect Usage: checkbrackets.exe filename.c\n\n");

	else	//if correct number of parameters are entered, run rest of program
	{
		csource = fopen(argv[1], "r");	//open file based on second argument entered
		/********check that file exists.  If file does not exist, end program.*************/
		if (csource == NULL)
		{
			printf("Cannot open file: Please check the filename you entered and try again.");
			exit(1);
		}
	
		checkbrackets = getc(csource);	//read first character from file

		while (checkbrackets != EOF)	//loop through each character until it reaches last character in file
		{
			switch (checkbrackets)	//switch statement used to allow counting of different brackets
			{
				case '(':
					countLeftBrace++;
					break;
				case ')':
					countRightBrace++;
					break;
				case '[':
					countLeftSquare++;
					break;
				case ']':
					countRightSquare++;
					break;
				case '{':
					countLeftCurly++;
					break;
				case '}':
					countRightCurly++;
					break;
			}
			checkbrackets = getc(csource);	//get next character in file
		}
		
		if (countLeftBrace != countRightBrace)	//if count of ( and ) are different tell user
		{
			printf("There are a different number of left and right braces - ()\n");
			printf("There are %d ('s & %d )'s\n", countLeftBrace, countRightBrace);
		}
		else printf("There are the same number of left and right braces ()\n");
		
		if (countLeftSquare != countRightSquare)	//if count of [ and ] are different tell user
		{
			printf("There are a different number of left and right square brackets - []\n");
			printf("There are %d ['s & %d ]'s\n", countLeftSquare, countRightSquare);
		}
		else printf("There are the same number of left and right braces []\n");
		
		if (countLeftCurly != countRightCurly) 	//if count of { and } are different tell user
		{
			printf("There are a different number of left and right curly brackets - {}\n");
			printf("There are %d {'s & %d }'s\n", countLeftCurly, countRightCurly);
		}
		else printf("There are the same number of left and right braces {}\n");
	
		fclose(csource);	//close file
	}
	
	return 0;
}