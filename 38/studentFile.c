/**************************************************************************************************

*Filename: studentFile.c
*Authors: Andrew Lamb
*Last Modified: 17/12/2012
*Description: 	For More than one Student:
				Program asks user if they want to: 
				-read student file, 
				-overwrite it with multiple students,  
				-add multiple new students to the file or
				-edit existing students.
				Based on chosen options, functions are called to read file, change details in struct
				and write to file.
				If edit function is requested, file is read into an array of structs, user can amend as
				required, and then new information from array is sent back to file, overwriting the file.
				
**************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>	//required for "exit" function

/******************* DECLARE STRUCT **********************/
struct student_details 
{
	char name[50];
	char phone[50];
	char studentNo[50];
};
/*********************************************************/

void clrscreen (void);	//DECLARE FUNCTION TO CLEAR THE SCREEN
void enterDetails (struct student_details *studentPointer);	//DECLARE FUNCTION TO WRITE TO STRUCT
void readFile (FILE *reader, char *fname);	//DECLARE FUNCTION TO READ FROM FILE
void writeFile (FILE *writer, struct student_details *studentPointer, char *fname);	//DECLARE FUNCTION TO WRTIE STRUCT TO FILE
void appendFile (FILE *appender, struct student_details *studentPointer, char *fname);	//DECLARE FUNCTION TO APPEND FILE CONTENTS
const int LENGTH_OF_FILENAME = 100;
int fLineCounter (int count, char *fname);
void sFileToStructs (int temp, FILE *readToStruct, struct student_details *multiStudentPointer, char *fname);
void editStudent (int temp, struct student_details *multiStudentPointer);
void overWriteEdits (int temp, FILE *writeSArrayToFile, struct student_details *multiStudentPointer, char *fname);

int main(void)
{
	FILE *studentFile;
	char option;
	struct student_details *studentPointer;
	studentPointer = (struct student_details*) malloc(sizeof(struct student_details));
	char filename[LENGTH_OF_FILENAME];
	char *fnPtr;
	fnPtr = (char*) malloc(sizeof(filename));
	fnPtr = &filename[0];
	int noOfStudents;
	int i;	//counter
	int temp = 0;
	char edit;
	char temporaryArray[50];
	int detail;
	
	clrscreen();
	
	if ((studentPointer == NULL) || (fnPtr == NULL))
	{
		printf("ERROR: Not enough memory to run this program\n");
		exit(2);
	}
	
	printf("Program will let you:\nView a file (20 lines at a time), \nOverwrite it's contents completely \nAppend to the file or\nEdit a student's details\n\nPlease enter the filename:");
	fgets(filename, LENGTH_OF_FILENAME, stdin);
	filename[strlen(filename)-1] = '\0';
	printf("\nWould you like to:\nview 'v',\noverwrite 'o',\nappend file 'a' or\nedit file 'e'?\n");
	scanf("%1c", &option);
	
	
	/****************** SECTION TO READ FROM FILE ***************************/
	if (option == 'v')
	{
		getchar();
		readFile(studentFile, fnPtr);	//CALL FILE READER FUNCTION
		printf("\n\n");
	}
	
	/****************** SECTION TO WRITE TO STRUCT AND THEN TO FILE *********/
	else if (option == 'o')
	{
		getchar();
		printf("\nFile will be changed from:\n");
		readFile(studentFile, fnPtr);	//CALL FILE READER FUNCTION
		printf("\n\n");
		
		printf("\nThese contents will be overwritten, are you sure you wish to continue?\n('y' for yes or 'n' for no):");
		scanf("%1c", &option);
		
		while (option != 'y' && option != 'n')
		{
			printf("Invalid choice selected. Please enter 'y' to continue or 'n' to cancel:");
			scanf("%1c", &option);
		}
		if (option == 'n') 
		{
			printf("Process to overwrite file has been cancelled.\n\n");
			return 5;	//Cancel write option and return 5 to exit program.
		}
		/************* WRITE TO FILE ****************/
		if (option == 'y')
		{
			getchar();
			printf("How Many Students would you like to add?\n");
			scanf("%3d", &noOfStudents);
			getchar();
			
			enterDetails(studentPointer);	//CALL FUNCTION TO WRITE TO STRUCT
			writeFile(studentFile, studentPointer, fnPtr);	//CALL FUNCTION TO WRITE TO FILE
			//Append additional students to file
			for (i = 2; i <= noOfStudents; i++)
			{
				enterDetails(studentPointer);	//CALL FUNCTION TO WRITE TO STRUCT
				appendFile (studentFile, studentPointer, fnPtr);	//CALL FUNCTION TO APPEND STUDENT(S) TO FILE
			}
			printf("\nFile contents have been changed to:\n");
			readFile(studentFile, fnPtr);	//CALL FUNCTION TO READ FILE AFTER CHANGES HAVE BEEN MADE
			printf("\n\n");
		}
	}
	
	/***************** SECTION TO APPEND NEW CONTENT TO THE FILE ************/
	else if (option == 'a')
	{
		getchar();
		printf("\nYou will be adding contents to the student file. Current Contents are:\n");
		readFile(studentFile, fnPtr);	//CALL FILE READER FUNCTION
		printf("\n\n");
		printf("How Many Students would you like to add?\n");
		scanf("%1d", &noOfStudents);
		getchar();
		for (i = 1; i <= noOfStudents; i++)
		{
			enterDetails(studentPointer);	//CALL FUNCTION TO WRITE TO STRUCT
			appendFile (studentFile, studentPointer, fnPtr);	//CALL FUNCTION TO APPEND STUDENT(S) TO FILE
		}
		printf("\nFile Contents have been changed to:\n\n");
		readFile(studentFile, fnPtr);
		printf("\n\n");
	}
	
	/***************** SECTION TO EDIT STUDENT DETAILS ALREADY IN THE FILE ************/
	else if (option == 'e')
	{
		temp = fLineCounter (temp, fnPtr);	//read line count	
		temp = (temp / 4) + 1;	//No of students in file is line count / 4. Add one to have one extra element in array.
		
		// DECLARE ARRAY OF STRUCTS AND ALLOCATE MEMORY ONLY IF EDIT FUNCTION REQUESTED BY USER
		struct student_details *multiStudentPointer;
		multiStudentPointer = (struct student_details*) malloc(sizeof(struct student_details) *temp);	//(multiply by value of temp)
		
		if (multiStudentPointer == NULL)	//check that enough memory exists
		{
			printf("ERROR: Not enough memory to run this program\n");
			exit(2);
		}
		
		temp = temp - 1;	//Sets temp to the number of students contained in file

		sFileToStructs(temp, studentFile, multiStudentPointer, filename);	//CALL FUNCTION TO READ STUDENT DETAILS FROM FILE INTO AN ARRAY OF STRUCTS

		while (edit != 'n')
		{
			editStudent(temp, multiStudentPointer);	//CALL FUNCTION TO EDIT A STUDENT

			printf("Would you like to edit another student 'y' or 'n'?\n");
			scanf("%1c", &edit);
			getchar();
		}	

		overWriteEdits (temp, studentFile, multiStudentPointer, filename);	//CALL FUNCTION TO OVERWRITE COMPLETE FILE WITH UPDATED STUDENTS DETAILS

		free(multiStudentPointer);
		printf("\nFile Contents have been changed to:\n\n");
		readFile(studentFile, fnPtr);
		printf("\n\n");
	}
	
	else printf("Invalid operator selected, Please try again.\n");

	free(studentPointer);
	free(fnPtr);
	
	return 0;
}

void clrscreen (void)
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

/****************** FUNCTION TO READ FROM FILE ***************************/
void readFile (FILE *reader, char *fname)
{
	int accessFile;
	int i; //counter
	char quit = 'x';
	
	//printf("fname in readFile:%s\n\n", fname);
	reader = fopen(fname, "r");
	for (i = 0; reader == NULL && i < 2; i++)
	{
		printf("Cannot open %s for reading\n", fname);
		printf("Please reenter filename:\n");
		fgets(fname, LENGTH_OF_FILENAME, stdin);
		fname[strlen(fname)-1] = '\0';
		reader = fopen(fname, "r");
	}
	if (reader == NULL && i == 2)
	{
		printf("Invalid filename entered 3 times. End Program.\n");
		exit(2);
	}
	
	if (reader != NULL) printf("File Contents Are:\n");
	
	i = 0;
	
	accessFile = getc(reader);
	while (i < 20 && accessFile != EOF && quit != 'q')
	{
		putchar(accessFile);
		accessFile = getc(reader);
		if (accessFile == '\n' || accessFile == '\r')
		{
			i++;
		}
	
		if (i == 20)
		{
			i = 0;
			printf("\nPress Return to Display 20 more lines or 'q' to quit:");
			scanf("%1c", &quit);
		}
	}
	
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

/**************** FUNCTION TO WRITE SINGLE STRUCT TO FILE **********************/
void writeFile (FILE *writer, struct student_details *studentPointer, char *fname)
{
	int i;	//counter
	int newline = '\n';
	
	writer = fopen(fname, "w");
	if (writer == NULL)
	{
		printf("Cannot open file for writing\n");
		exit(1);
	}
	
	putc('x', writer);
	putc('x', writer);
	putc('x', writer);
	putc(newline, writer);
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
	putc(newline, writer);
	
	fclose(writer);
}
/************************************************************************/

/************************* FUNCTION TO APPEND FILE **********************/
void appendFile (FILE *appender, struct student_details *studentPointer, char *fname)
{
	int i;	//counter
	int newline = '\n';
	appender = fopen(fname, "a");
	if (appender == NULL)
	{
		printf("Cannot open file for reading\n");
		exit(1);
	}
	
	putc('x', appender);
	putc('x', appender);
	putc('x', appender);
	putc(newline, appender);
	for (i = 0; studentPointer->name[i] != '\0'; i++)
	{
		putc(studentPointer->name[i], appender);
	}
	putc(newline, appender);
	
	for (i = 0; studentPointer->phone[i] != '\0'; i++)
	{
		putc(studentPointer->phone[i], appender);
	}
	putc(newline, appender);
	
	for (i = 0; studentPointer->studentNo[i] != '\0'; i++)
	{
		putc(studentPointer->studentNo[i], appender);
	}
	putc(newline, appender);

	fclose(appender);
}

/*********************** COUNT NUMBER OF LINES IN FILE **************************************/
int fLineCounter (int count, char *fname)
{
	FILE *lineCount;
	int accessFile;
	
	printf("fLineCounter start count is: %d\n", count);
	
	lineCount = fopen(fname, "r");
	if (lineCount == NULL)
	{
		printf("Cannot open file for reading\n");
		exit(1);
	}
	
	accessFile = getc(lineCount);
	while (accessFile != EOF)
	{
		if (accessFile == '\n') count++;
		accessFile = getc(lineCount);
	}
	
	printf("fLineCounter end count is: %d\n", count);
	
	fclose(lineCount);	
	return count;
}
/********************************************************************************************/


/********************* READ STUDENTS DETAILS FROM FILE TO ARRAY OF STRUCTS ******************/		
void sFileToStructs (int temp, FILE *readToStruct, struct student_details *multiStudentPointer, char *fname)
{
	int i;	//counter
	char temporaryArray[50];
	int detail;
	
	readToStruct = fopen(fname, "r");
	
	if (readToStruct == NULL)	//check that file opens OK
	{
		printf("Cannot open file for writing\n");
		exit(1);
	}
	
	for (i = 0; i < temp; i++)	//(replace 5 with new temp value from calculation)
	{
		fgets(temporaryArray, 50, readToStruct);	//replace studentDetails.txt with user-provided filename
		//printf("%s", temporaryArray);
		temporaryArray[strlen(temporaryArray)-1] = '\0';
		if (strcmp(temporaryArray, "xxx") == 0) 
		{
			detail = 0;
		}
		if (detail == 0)
		{
			fgets (temporaryArray, 50, readToStruct);
			temporaryArray[strlen(temporaryArray)-1] = '\0';
			strcpy (multiStudentPointer[i].name, temporaryArray);
			detail = 1;
		}
		if (detail == 1)
		{
			fgets (temporaryArray, 50, readToStruct);
			temporaryArray[strlen(temporaryArray)-1] = '\0';
			strcpy (multiStudentPointer[i].phone, temporaryArray);
			detail = 2;
		}
		if (detail == 2)
		{
			fgets (temporaryArray, 50, readToStruct);
			temporaryArray[strlen(temporaryArray)-1] = '\0';
			strcpy (multiStudentPointer[i].studentNo, temporaryArray);
		}
	}
	fclose (readToStruct);	//close file
}
/********************************************************************************************/


/********************* ALLOW USER TO CHANGE A STUDENT ***************************************/
void editStudent(int temp, struct student_details *multiStudentPointer)
{	
	int stuOption;
	int i;	//counter
	char temporaryArray[50];
	
	for (i = 0; i < temp; i++)	
	{
		printf("%d: %s\n", i, multiStudentPointer[i].name);
	}
	printf("Which student would you like to edit? (ENTER Number):\n");
	scanf("%3d", &stuOption);
	getchar();
	
	printf("Edit Student Name:");
	fgets (temporaryArray, 50, stdin);
	temporaryArray[strlen(temporaryArray)-1] = '\0';
	strcpy (multiStudentPointer[stuOption].name, temporaryArray);
	
	printf("Edit Student Phone Number:");
	fgets (temporaryArray, 50, stdin);
	temporaryArray[strlen(temporaryArray)-1] = '\0';
	strcpy (multiStudentPointer[stuOption].phone, temporaryArray);
	
	printf("Edit Student Number:");
	fgets (temporaryArray, 50, stdin);
	temporaryArray[strlen(temporaryArray)-1] = '\0';
	strcpy (multiStudentPointer[stuOption].studentNo, temporaryArray);
}
/********************************************************************************************/


/***************** OVERWRITE COMPLETE FILE WITH UPDATED STUDENTS DETAILS ********************/
void overWriteEdits (int temp, FILE *writeSArrayToFile, struct student_details *multiStudentPointer, char *fname)
{
	int i;	//first counter
	int j;	//second counter
	int newline = '\n';
	
	writeSArrayToFile = fopen(fname, "w");
	
	if (writeSArrayToFile == NULL)	//check file opens
	{
		printf("Cannot open file for writing\n");
		exit(1);
	}
	for (i = 0; i < temp; i++)	//replace 5 with temp
	{
		putc('x', writeSArrayToFile);
		putc('x', writeSArrayToFile);
		putc('x', writeSArrayToFile);
		putc(newline, writeSArrayToFile);

		for (j = 0; multiStudentPointer[i].name[j] != '\0'; j++)
		{
			putc(multiStudentPointer[i].name[j], writeSArrayToFile);
		}
		putc (newline, writeSArrayToFile);
	
		for (j = 0; multiStudentPointer[i].phone[j] != '\0'; j++)
		{
			putc(multiStudentPointer[i].phone[j], writeSArrayToFile);
		}
		putc (newline, writeSArrayToFile);
	
		for (j = 0; multiStudentPointer[i].studentNo[j] != '\0'; j++)
		{
			putc(multiStudentPointer[i].studentNo[j], writeSArrayToFile);
		}
		putc (newline, writeSArrayToFile);
	}
	
	fclose (writeSArrayToFile);
}
/********************************************************************************************/