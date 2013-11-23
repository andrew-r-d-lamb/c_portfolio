/**************************************************************************************************

*Filename: readWriteToStructFileC.c
*Authors: Andrew Lamb
*Last Modified: 10/12/2012
*Description: 	Program asks user if they want to read a file or overwrite the details in the file.
				Based on chosen options, functions are called to read file, change details in struct
				and write to file.
				
**************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>	//required for "exit" function

/******************* DECLARE STRUCT **********************/
struct student_details 
{
	char name[50];
	char phone[30];
	char studentNo[20];
};
/*********************************************************/

void enterDetails (struct student_details *studentPointer);	//DECLARE FUNCTION TO WRITE TO STRUCT
void readFile (FILE *reader);	//DECLARE FUNCTION TO READ FROM FILE
void writeFile (FILE *writer, struct student_details *studentPointer);	//DECLARE FUNCTION TO WRTIE STRUCT TO FILE

int main(void)
{
	FILE *studentFile;
	char option;
	struct student_details *studentPointer;
	studentPointer = (struct student_details*) malloc(sizeof(struct student_details));
	
	if (studentPointer == NULL)
	{
		printf("ERROR: Not enough memory to run this program\n");
		exit(2);
	}
	
	printf("\nWould you like to view Student Details 'v' or overwrite them 'o'?\n");
	scanf("%1c", &option);
	
	/****************** SECTION TO READ FROM FILE ***************************/
	if (option == 'v')
	{
		printf("\nFile contents are:\n\n");
		readFile(studentFile);	//CALL FILE READER FUNCTION
		printf("\n\n");
	}
	
	/****************** SECTION TO WRITE TO STRUCT AND THEN TO FILE *********/
	else if (option == 'o')
	{
		getchar();
		printf("\nFile will be changed from:\n");
		readFile(studentFile);	//CALL FILE READER FUNCTION
		printf("\n\n");
		enterDetails(studentPointer);	//CALL FUNCTION TO WRITE TO STRUCT
		writeFile(studentFile, studentPointer);	//CALL FUNCTION TO WRITE TO FILE
		
		printf("\nFile contents have been changed to:\n");
		readFile(studentFile);	//CALL FUNCTION TO READ FILE AFTER CHANGES HAVE BEEN MADE
		printf("\n\n");
	}
	
	else printf("Invalid operator selected, Please try again.\n");

	free(studentPointer);
	
	return 0;
}

/****************** FUNCTION TO READ FROM FILE ***************************/
void readFile (FILE *reader)
{
	int accessFile;
	reader = fopen("studentDetails.txt", "r");
	if (reader == NULL)
	{
		printf("Cannot open file for reading\n");
		exit(1);
	}
	
	do
	{
		accessFile = getc(reader);
		putchar(accessFile);
	}	
	while (accessFile != EOF);
	
	fclose(reader);
}
/************************************************************************/

/**************** FUNCTION TO WRITE TO STRUCT ***************************/
void enterDetails (struct student_details *studentPointer)
{
	int length;
	printf("\nEnter Student Name:\n");
	fgets(studentPointer->name, 50, stdin);
	length = strlen(studentPointer->name);
	studentPointer->name[length - 1] = '\0';
	
	printf("\nEnter Student Phone Number:\n");
	fgets(studentPointer->phone, 30, stdin);
	length = strlen(studentPointer->phone);
	studentPointer->phone[length - 1] = '\0';
	
	printf("\nEnter Student Number:\n");
	fgets(studentPointer->studentNo, 20, stdin);
	length = strlen(studentPointer->studentNo);
	studentPointer->studentNo[length - 1] = '\0';
}
/************************************************************************/

/**************** FUNCTION TO WRITE STRUCT TO FILE **********************/
void writeFile (FILE *writer, struct student_details *studentPointer)
{
	int i;	//counter
	int newline = '\n';
	
	writer = fopen("studentDetails.txt", "w");
	if (writer == NULL)
	{
		printf("Cannot open file for reading\n");
		exit(1);
	}
	
	for (i = 0; studentPointer->name[i] != '\0'; i++)
	{
		putc(studentPointer->name[i], writer);
	}
	putc(newline, writer);
	
	for (i = 0; studentPointer->phone[i] != '\0'; i++)
	{
		putc(studentPointer->phone[i], writer);
	}
	putc(newline, writer);
	
	for (i = 0; studentPointer->studentNo[i] != '\0'; i++)
	{
		putc(studentPointer->studentNo[i], writer);
	}
	
	fclose(writer);
}
/************************************************************************/