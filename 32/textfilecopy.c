/*************************************************************************************************

*Filename: textfilecopy.c
*Authors: Andrew Lamb
*Last Modified: 24/12/2012
*Description:	Program copies text from one file to another

*************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	FILE *copyfrom;
	FILE *copyto;
	char fname1[100];
	char fname2[100];
	int length;
	char temp;

	printf("\n\n\n\n\n\nThis program will copy your text file to another file\nPress ENTER to continue or 'q' to quit:\n");
	
	if(getchar() == 'q')
	{
		printf("\n\n\n\n\n\n\n\n\nGoodbye\n\n\n\n\n\n\n\n");
		exit(2);
	}
	
	printf("Enter Name of file you would like to copy from:\n");
	fgets(fname1, 100, stdin);
	length = strlen(fname1);
	fname1[length - 1] = '\0';	//replace '\n' at end of fgets sentence with '\0'
	
	copyfrom = fopen(fname1, "r");	//open FILE for reading copyfrom with filename specified by user in fname1
	if (copyfrom == NULL)	//check that file can be opened
	{
		printf("Error Opening the file you would like to copy from\n");
		exit(0);
	}
	
	printf("\nEnter Name of file you would like to copy to:\n!!!CAUTION: CONTENTS OF FILE WILL BE OVERWRITTEN!!!\n");
	fgets(fname2, 100, stdin);
	length = strlen(fname2);
	fname2[length - 1] = '\0';	//replace '\n' at end of fgets sentence with '\0'
	
	copyto = fopen(fname2, "w");	//open FILE for writing copyfrom with filename specified by user in fname2
	if (copyto == NULL)	//check that file can be opened
	{
		printf("Error Opening the file you would like to copy to\n");
		exit(0);
	}
	
	while ( (temp = getc(copyfrom)) != EOF )	//run through each character in copyfrom FILE until End of File reached
	{
		putc(temp, copyto);	//write each character to copyto FILE
	}

	fclose(copyfrom);
	fclose(copyto);

	printf("\n\n\n\n\n\n\n\n\n\n\nCopy Completed\n");

	return 0;	//all OK
}