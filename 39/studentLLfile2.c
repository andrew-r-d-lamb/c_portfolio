/*************************************************************************************************

*Filename: studentLLfile2.c
*Authors:
*Last Modified:
*Description:	Program stores students in file students.txt and automatically retrieves this information when run
				User is given option to add students, edit students, delete students, display all students or quit
				While program is running, student information is stored in a linked list

*************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student_details
{
	int sNo;
	char fName[15];
	char lName[15];
	char phone[20];
	struct student_details *next;
} 
student;

student *createAnElement (void);
student *addStudent (student *first);
student *removeStudent (student *first);
student *elementAtIndex (student *element, int index);

int fLineCounter (int lineCount);
student *importStudent (student *first, FILE *sFile);
void *overWrite (student *aStudent);
student *editStudent (student *first);

void clrscreen (void);
void menu (void);
void userInput (student *aStudent);
void display (student *aStudent);
void displayAll (student *aStudent);


int main (void)
{
	int choice;
	char option;
	student *first = NULL;
	int noOfStudents;
	int i;	//counter
	char dump[100];
	
	clrscreen();
	
	//Automatically Import Students from file if there are any in it
	noOfStudents = 0;
	noOfStudents = fLineCounter (noOfStudents);
	FILE *sFile;
	sFile = fopen ("students.txt", "r");
	if (sFile == NULL)
	{
		printf("Cannot import student details from file\n");
		printf("Unable to open file: 'students.txt' for reading\n");
	}
	else
	{
		fgets(dump, 100, sFile);	//dump firstline of file
		for(i = 1; i < noOfStudents; i++)
		{
			first = importStudent (first, sFile);
		}
		fclose (sFile);	
	}
	
	do
	{
		menu();
		scanf("%2d", &choice);
		
		switch (choice)
		{
			case 1: //add a student
				first = addStudent(first);
				break;
			case 2:	//edit a student
				first = editStudent(first);
				getchar();
				printf ("\n\nYou have edited a record in program memory. \nWould you like to overwrite file contents 'y' or 'n'?\n");
				scanf ("%c", &option);
				while (option != 'n' && option != 'y')
				{
					printf("Invalid option selected. Please enter 'y' or 'n':\n");
					getchar();
					scanf("%c", &option);
				}
				if (option == 'n') break;	
				if (option == 'y') 
				{
					overWrite(first);
					break;
				}
			case 3:	//remove a student
				first = removeStudent(first);
				getchar();
				printf ("\n\nYou have deleted a record from program memory. \nWould you like to overwrite file contents 'y' or 'n'?\n");
				scanf ("%c", &option);
				while (option != 'n' && option != 'y')
				{
					printf("Invalid option selected. Please enter 'y' or 'n':\n");
					getchar();
					scanf("%c", &option);
				}
				if (option == 'n') break;	
				if (option == 'y') 
				{
					overWrite(first);
					break;
				}
			case 4:	//display all students
				displayAll(first);
				break;
		}
	}while (choice != 0);
	
	return 0;
}

//Allocate a new element and initialise its values
student *createAnElement (void)
{
	student *newElement = (student *) malloc(sizeof(student));	//allocate memory
	if (newElement == NULL)
	{
		printf("ERROR: Not Enough Memory to continue\n");
		exit (5);
	}
	newElement->sNo = 0;
	strcpy(newElement->fName, "");
	strcpy(newElement->lName, "");
	strcpy(newElement->phone, "");
	newElement->next = NULL;
	return newElement;
}

//User Adds new student to list
student *addStudent (student *first)
{
	student *last;
	student *new = createAnElement();
	
	userInput(new);	//call function for user to input student details
	
	//add new (student) to the end of the list
	if (first != NULL) 	
	{
		for (last = first; last->next != NULL; last = last->next);	//loop from first element until pointer to next element is NULL
		last->next = new;	//point the current last element at the new last element
		/************** APPEND NEW TO FILE *****************/
		FILE *sFile;
		sFile = fopen("students.txt", "a");
		fprintf (sFile, "%-9d%-14s%-14s%-19s\n", new->sNo, new->fName, new->lName, new->phone);
		fclose (sFile);
	}
	else 
	{
		first = new;	//if there is no first student, assign new (student) as first element
		/********** ELSE WRITE FIRST ELEMENT TO NEW FILE *************/
		FILE *sFile;
		sFile = fopen("students.txt", "w");
		fprintf (sFile, "%-9s%-14s%-14s%-19s\n", "S No", "First Name", "Last Name", "Phone No"); 
		fprintf (sFile, "%-9d%-14s%-14s%-19s\n", new->sNo, new->fName, new->lName, new->phone);
		fclose (sFile);
	}
	return first;
}

//Remove a student from the list
student *removeStudent (student *first)
{
	student *remove;
	student *previousToRemove;
	int index;
	int counter;
	
	if (first == NULL)	//if there are no elements in list
	{
		printf("There are no students details to remove\n");
		return first;
	}
	
	printf("Which student index would you like to delete? (starting from 0)\n");
	scanf("%9d", &index);
	
	//Remove first student element
	if (index == 0)
	{
		student *next = first->next;	//assign pointer to next element
		free(first);	//free the memory being used by the first element
		return next;	//return next as first
	}
	
	//Remove another element which is not element 0
	remove = elementAtIndex(first, index);	//point remove at the address you want to remove based on the index
	previousToRemove = elementAtIndex(first, index - 1);	//point previousToRemove at the address of the element which comes before the element you want to remove
	
	if (remove == NULL)	//if remove points at NULL
	{
		printf("Unable to remove student. No student found at index %d.", index);
		return first;
	}
	
	previousToRemove->next = remove->next;	//sets the next pointer of the element before the one you want to remove to point at the element after the one you want to remove
	free(remove);	//frees the memory of the element pointed at by remove (removes this student element from list)
	return first;	
}

//Find element at index and return a pointer to it
student *elementAtIndex (student *element, int index)
{
	for (; index > 0 && element != NULL; index--, element = element->next);
	return element;
}

//Clears command prompt screen
void clrscreen (void)
{
	int i;
	for (i = 0; i < 25; i++) printf ("\n");
}

//Display Menu
void menu (void)
{
	printf("0 - Quit\n1 - Add\n2 - Edit\n3 - Remove\n4 - Display All\nEnter Option: ");
	fflush(stdout);
}

//allows user to input values into a student element
void userInput (student *aStudent)
{
	printf("Enter Student Details:\n");
	printf("StudentNumber, FirstName, LastName, PhoneNo\n");
	printf("e.g. 123456 Bugs Bunny 7774167\n");
	scanf("%9d %14s %14s %19s", &aStudent->sNo, &aStudent->fName, &aStudent->lName, &aStudent->phone);
	display (aStudent);
}

//display one student element
void display (student *aStudent)
{
	//printf("Student No: %d, First Name: %s, Last Name: %s, Phone: %s\n", aStudent->sNo, aStudent->fName, aStudent->lName, aStudent->phone);
	printf ("%-9d%-14s%-14s%-19s\n", aStudent->sNo, aStudent->fName, aStudent->lName, aStudent->phone);
}

//display all student elements
void displayAll (student *aStudent)
{
	int counter = 0;
	if (aStudent == NULL)
	{
		printf("\n\n\n\n\nNo Student Records to display\n\n\n\n\n\n");
		return;
	}
	
	printf("Here are all the student records:\n");
	printf ("%-9s%-9s%-14s%-14s%-19s\n", "Index No", "S No", "First Name", "Last Name", "Phone No");
	for (; aStudent != NULL; aStudent = aStudent->next)
	{
		printf("%-9d", counter++);
		display(aStudent);
	}	
	printf("\n\n\n");
}

//Count Number of lines in file. Number of lines == Number of Students.
int fLineCounter (int lineCount)
{
	FILE *sFile;
	int readCharacters;
	
	//printf("fLineCounter start count is: %d\n", lineCount);	//check start count
	
	sFile = fopen("students.txt", "r");
	if (sFile == NULL)
	{
		printf("Cannot open 'students.txt' for reading\n");
		return lineCount;
	}
	
	readCharacters = getc(sFile);
	while (readCharacters != EOF)
	{
		if (readCharacters == '\n') lineCount++;
		readCharacters = getc(sFile);
	}
	
	//printf("fLineCounter end count is: %d\n", lineCount);	//check end count
	
	fclose(sFile);
	return lineCount;
}

//Import A Student from file into linked list - used in a loop with condition taken from fLineCounter 
student *importStudent (student *first, FILE *sFile)
{
	student *last;
	student *new = createAnElement();
	
	fscanf (sFile, "%9d %14s %14s %19s", &new->sNo, &new->fName, &new->lName, &new->phone);
	
	//add new (student) to the end of the list
	if (first != NULL) 	
	{
		for (last = first; last->next != NULL; last = last->next);	//loop from first element until pointer to next element is NULL
		last->next = new;	//point the current last element at the new last element
	}
	else 
	{
		first = new;	//if there is no first student, assign new (student) as first element
	}
	return first;
}

//Option to Overwrite File Contents after removing/editing a student
void *overWrite (student *aStudent)
{
	FILE *sFile;
	int counter = 0;
	
	if (aStudent == NULL)
	{
		printf("\n\n\n\n\nNo students to output to file\n\n\n\n\n");
		
	}
	
	sFile = fopen("students.txt", "w");
	if (sFile == NULL)
	{
		printf("Cannot open 'students.txt' for writing\n");
		exit(5);
	}
	
	//output headings
	fprintf (sFile, "%-9s%-14s%-14s%-19s\n", "S No", "First Name", "Last Name", "Phone No");

	for (; aStudent != NULL; aStudent = aStudent->next)
	{
		fprintf (sFile, "%-9d%-14s%-14s%-19s\n", aStudent->sNo, aStudent->fName, aStudent->lName, aStudent->phone);
	}

	fclose (sFile);
}

//Edit a Student
student *editStudent (student *first)
{
	student *edit;
	//student *previousToedit;
	int index;
	//int counter;
	int option;
	
	if (first == NULL)	//if there are no elements in list
	{
		printf("There are no students details to edit\n");
		return first;
	}
	
	printf("Which student index would you like to edit? (starting from 0)\n");
	scanf("%9d", &index);

	edit = elementAtIndex(first, index);	//point edit at the address you want to edit based on the index
	
	if (edit == NULL)	//if edit points at NULL
	{
		printf("Unable to edit student. No student found at index %d.", index);
		return first;
	}
	
	display(edit);
	do
	{
		printf("What would you like to edit?\n");
		printf("0 - Exit\n1 - Student Number\n2 - Student First Name\n3 - Student Last Name\n4 - Student Phone No\nEnter Option: ");
		fflush(stdout);
		scanf("%2d", &option);
		
		switch (option)
		{
			case 1:
				printf("Enter student No:\n");
				scanf("%9d", &edit->sNo);
				break;
			case 2:
				printf("Enter student's first name:\n");
				scanf("%14s", &edit->fName);
				break;
			case 3:
				printf("Enter student's last name:\n");
				scanf("%14s", &edit->lName);
				break;
			case 4:
				printf("Enter student's telephone number\n");
				scanf("%19s", &edit->phone);
				break;
		}
	} while (option != 0);
	return first;	
}