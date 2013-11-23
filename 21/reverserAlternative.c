/*************************************************************************************************

*Filename: reverserAlternative.c
*Authors: Andrew Lamb
*Last Modified: 24/12/2012
*Description:	Program that reverses the order of the letters in words, but not the whole sentence, 
				and then prints them backwards
				Program uses a temporary char to switch letters

*************************************************************************************************/

#include <stdio.h>
//#include <stdlib.h> //include if Malloc is wanted
#include <string.h> //include if str functions are needed

const int SENTENCE_LENGTH = 10000; //define constant variable of 10000 characters
//void swap_characters_in_word (char *words, int start_of_word); //declare function

int main(void)
{
	char words[SENTENCE_LENGTH]; //set word array
	int counterPos = 0;
	int counterNeg = 0;
	int get_length;
	int start_of_word;
	int end_of_word;
	char temporary;
	
	//Request User Inputs a Sentence
	printf("Please enter a sentence:\n");
	
	//Store User Input into sentence array
	fgets(words, SENTENCE_LENGTH, stdin); //NB fgets output ends with '\n' '\0'
	
	//(Check that program has stored user input)
	printf("You entered: %s\n", words);
	get_length = strlen(words); //Gets length of sentence
	
	words[get_length -1] = ' '; //replace '\n' with ' ' could alternatively loop through sentence until '\n' found and then replace it

	//Loop through sentence:
	for (counterPos = 0; words[counterPos] != '\0'; counterPos++) //run counter until '\0' reached in sentence
	{	
		//printf("CounterPos:%d\n", counterPos);
		if (words[counterPos] == ' ') //if positive counter reaches a space character in sentence:
		{	
			//end_of_word = words[counterPos - 1];
			end_of_word = counterPos - 1;
			//printf ("%d: %c\n", counterPos, end_of_word);
			for (counterNeg = (counterPos - 1); words[counterNeg] != '\0' && words[counterNeg] != ' '; counterNeg--) //subtracts one from counterPos so that it's not a ' ', runs negative counter backwards until  it reaches '\0' or another ' ' character
			{
				//start_of_word = words[counterNeg];
				start_of_word = counterNeg;
				//printf ("%c", words[counterNeg]);
			}
			//printf ("Last Letter is: %d: %c\n", counterPos -1, end_of_word);
			//printf ("First Letter is: %d: %c\n", counterNeg +1, start_of_word);	
			//printf("Before You Entered: %s\n", words);
			for (end_of_word = counterPos - 1; end_of_word >= start_of_word; end_of_word--)
			{
					//printf("Before Switch - Start[]:%c End[]: %c\n", words[start_of_word], words[end_of_word]);
					temporary = words[end_of_word];
					words[end_of_word] = words[start_of_word];
					words[start_of_word] = temporary;
					//printf("After Switch - Start[]:%c End[]: %c\n", words[start_of_word], words[end_of_word]);
					start_of_word++;
			}
			//printf("After You Entered: %s\n", words);
		}
	}
	printf ("You Entered: %s\n", words);	
	return 0;
}
/*
void swap_characters_in_word (char *words, int start_of_word) //function to reverse letters in words in a sentence
{
	int counterPos = 0;
	int counterNeg = 0;
}
*/