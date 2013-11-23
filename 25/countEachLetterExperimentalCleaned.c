/*************************************************************************************************

*Filename: countEachLetterExperimentalCleaned.c
*Authors: Andrew Lamb
*Last Modified: 24/12/2012
*Description:	Program takes sentence from user and counts number of each letter of alphabet entered in sentence
				Program runs a loop so user can input more sentences
				NOTE: Program only counts lower-case letters

*************************************************************************************************/

#include <stdio.h>
#include <string.h>

const int SENTENCE_LENGTH = 10000;
void welcome (void);
void goodbye (void);

int main (void)
{
	int alphabetCount[27];	
	alphabetCount[26] = '\0';
	char alphabet[27]= {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '\0'};
	char words[SENTENCE_LENGTH];
	int i = 0;	//counter
	int j = 0; 	//counter
	int sum;
	int quits;
	
	welcome();	//call welcome function
	
	printf("This Program will count the amount of each letter entered.\n\n");
	printf("Press ENTER:");
	
	do	//starts loop which runs at least once and then give user option to quit or run again
	{
		getchar();	//there is a character left somewhere in memory, so the do-while loop won't allow user to input a sentence after the first time unless getchar() is included here (or perhaps somewhere else)?
		printf("\nPlease Enter a sentence:\n");
		fgets(words, SENTENCE_LENGTH, stdin);
		
		//!!! set all values in int alphabetCount to 0 except for the last one !!!
		for (i = 0; i < 26; i++)
		{
			alphabetCount[i] = 0;
		}
				
		printf("\nYour sentence contains: \n");
		
		//!!! outer loop runs through each letter in the alphabet !!!
		for (i = 0; alphabet[i] != '\0'; i++)	//note last alphabet char in array was assigned '\0' value
		{
			sum = 0;							//set sum to 0 at the start of the loop
			for (j = 0; words[j] != '\0'; j++)	//inner loop runs through each letter in the sentence of words entered
			{
				if (alphabet[i] == words[j])	//if alphabet character same as sentence word char
				{
					sum = sum + 1;				//adds one to sum each time characters are the same
				}
			}
			
			alphabetCount[i] = sum;				//sets alphabetCount array number to the sum of the individual letter counted
			
			//!!! Only Print Quantity of Letters for letters that are in sentence (no 0 values) !!!
			if(alphabetCount[i] != 0)
			{
				if (alphabetCount[i] == 1) printf ("%d%c, ", alphabetCount[i], alphabet[i]);
				else printf("%d%c's, ", alphabetCount[i], alphabet[i]);
			}	
		}
		
		printf ("\n\nwould you like to enter another sentence y\\n?");
		
		//quits = '\n';
		//do
		//{
			quits = getchar();
		//}
		//while (quits == '\n' && quits == '\0');
		//printf("%c\n", quits);
		
	} while(quits != 'n');
	
	goodbye();	//call goodbye function
	
	return 0;	//All OK
}	//END OF MAIN

void welcome (void)
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n!!!!!!!!!!!!!!!!!!!!!!!!   WELCOME   !!!!!!!!!!!!!!!!!!!!\n\n\n\n\n\n\n\n\n\n");
}

void goodbye (void)
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n!!!!!!!!!!!!!!!!!! Thank you. Come again !!!!!!!!!!!!!!!!\n\n\n\n\n\n\n\n\n\n");
}
