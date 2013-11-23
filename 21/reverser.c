/*************************************************************************************************

*Filename: reverser.c
*Authors: Andrew Lamb
*Last Modified: 24/12/2012
*Description:	Program that reverses the order of the letters in words, but not the whole sentence, 
				and then prints them backwards

*************************************************************************************************/

#include <stdio.h>
//#include <stdlib.h> //include if Malloc is wanted
#include <string.h> //include if str functions are needed

const int SENTENCE_LENGTH = 10000; //define constant variable of 10000 characters

int main(void)
{
	char sentence[SENTENCE_LENGTH]; //set sentence array
	int counterPos = 0;
	int counterNeg = 0;
	int get_length;
		
	//Request User Inputs a Sentence
	printf("Please enter a sentence:\n");
	
	//Store User Input into sentence array
	fgets(sentence, SENTENCE_LENGTH, stdin); //NB fgets output ends with '\n' '\0'
	
	//(Check that program has stored user input)
	printf("You entered: %s", sentence);
	get_length = strlen(sentence); //Gets length of sentence
	
	//(Check length gotten) Note that length is one character longer than counted as strlen counts the '\n'
	//printf("Length: %d\n\n\n",get_length); //was a check on length
	
	//All words entered in string have a space ' ' separating them. To keep consistency, change second last character from '\n' to ' '
	sentence[get_length -1] = ' '; //replace '\n' with ' ' could alternatively loop through sentence until '\n' found and then replace it
	
	printf ("You entered: ");
	//Loop through sentence
	for (counterPos = 0; sentence[counterPos] != '\0'; counterPos++) //run counter until '\0' reached in sentence
		{		
		if (sentence[counterPos] == ' ') //if positive counter reaches a space character in sentence:
			{
			//printf ("%d\n",counterPos); //was a check			
			for (counterNeg = (counterPos - 1); sentence[counterNeg] != '\0' && sentence[counterNeg] != ' '; counterNeg--) //subtracts one from counterPos so that it's not a ' ', runs negative counter backwards until  it reaches '\0' or another ' ' character
				{
				//printf ("neg:%d\n",counterNeg); //another check on progress
				printf ("%c", sentence[counterNeg]); //prints characters individually based on nested for conditions
				}
			printf(" "); //prints a space back between words
			}
		}
		
	return 0;
}