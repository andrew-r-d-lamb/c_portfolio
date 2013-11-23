/**************************************************************************************************

*Filename: fileReader.c
*Authors: Andrew Lamb
*Last Modified: 03/12/2012
*Description: Program reads contents of a file 20 lines at a time

**************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>	//required for "exit" function

int main(void)
{
	FILE *fileToBeRead;
	char filename[100];
	int words;
	int counter = 0;
	char quit = 'x';
	
	printf("Enter Name of the File you would like to view\n");
	fgets(filename, 100, stdin);
	filename[strlen(filename)-1] = '\0';
	
	fileToBeRead = fopen(filename, "r");
	if (fileToBeRead == NULL)	
	{
		printf("Cannot open file for reading \n");
		exit(1);
	}

	words = getc(fileToBeRead);
	
	while (counter < 21 && words != EOF && quit != 'q')
	{
		putchar(words);
		words = getc(fileToBeRead);
		if (words == '\n' || words == '\r')
		{
			counter++;
		}
		if (counter == 20)
		{
			counter = 0;			
			printf("\nPress Return to Display 20 more lines or 'q' to quit\n");
			scanf("%c", &quit);
		}
	}

	fclose(fileToBeRead);
	return 0;
}