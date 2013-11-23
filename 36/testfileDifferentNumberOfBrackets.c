/**************************************************************************************************

*Filename: fileReader.c
*Authors: Andrew Lamb
*Last Modified: 03/12/2012
*Description: Program compares 2 files to see if they are the same

**************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>	//required for "exit" function

int main(int argc, char *argv[])
{
	FILE *csource;
	char filename[100;
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
	
		checkbrackets = getc(csource);

		while (checkbrackets != EOF)
		{
			switch (checkbrackets
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
			
			checkbrackets = getc(csource);
		}
		
		if (countLeftBrace != countRightBrace) printf("There are a different number of left and right braces - ()\n");
		else printf("There are the same number of left and right braces ()\n");
		
		if (countLeftSquare != countRightSquare) printf("There are a different number of left and right square brackets - []\n");
		else printf("There are the same number of left and right braces []\n");
		
		if (countLeftCurly != countRightCurly printf("There are a different number of left and right curly brackets - {}\n");
		else printf("There are the same number of left and right braces {}\n");
	}
	
	return 0;
}