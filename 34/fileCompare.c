/**************************************************************************************************

*Filename: fileCompare.c
*Authors: Andrew Lamb
*Last Modified: 03/12/2012
*Description: Program compares 2 files to see if they are the same

**************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>	//required for "exit" function

int main(int argc, char *argv[])	//allow command line arguments
{
	FILE *fileOne;	//declare file pointer variable
	FILE *fileTwo;	//declare file pointer variable
	int testOne;
	int testTwo;
	
	if (argc != 3) printf("\nIncorrect Number of Parameters Entered.\nCorrect Usage: fileCompare.exe fileNameOne.txt fileNameTwo.txt\n");	//Check that correct number of arguments are entered. If not, prompt user with Correct Usage.
	
	else	//if correct number of parameters are entered, run rest of program
	{
		fileOne = fopen(argv[1], "r");	//open file based on second argument entered
		/********check that file exists.  If file does not exist, end program.*************/
		if (fileOne == NULL)	
		{
			printf("Cannot open fileOne for reading \n");
			exit(1);
		}
		
		fileTwo = fopen(argv[2], "r");	//open file based on third argument entered
		/********check that file exists.  If file does not exist, end program.*************/
		if (fileTwo == NULL)	
		{
			printf("Cannot open fileTwo for reading \n");
			exit(1);
		}	

		else
		{
			testOne = getc(fileOne);	//assign first character of fileOne to testOne
			testTwo = getc(fileTwo);	//assign first character of fileTwo to testTwo
			
			/***************Run Loop While testOne and testTwo are not at the end of file and while they are equal to each other**************/
			while ((testOne != EOF) && (testTwo != EOF) && (testOne == testTwo))
			{
				//putchar(testOne);	//was a test that file characters were being read correctly
				testOne = getc(fileOne);
				//putchar(testTwo);	//was a test that file characters were being read correctly
				testTwo = getc(fileTwo);
			}
			
			if (testOne == testTwo) printf("\nFiles are identical\n");	//if files were the same, tell user
			else if (testOne != testTwo) printf("\nFiles are not identical\n");	//if files were not the same, tell user
		}
		
		fclose(fileOne);	//close fileOne
		fclose(fileTwo);	//close fileTwo
	}
	
	return 0;	//All OK
}	//end of main