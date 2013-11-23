/*************************************************************************************************

*Filename: reverserFunc.c
*Authors: Andrew Lamb
*Last Modified: 24/12/2012
*Description:	Program that reverses the order of the letters in words, function reverses characters for the individual words

*************************************************************************************************/

#include <stdio.h>
//#include <stdlib.h> //include if Malloc is wanted
#include <string.h> //include if str functions are needed

const int SENTENCE_LENGTH = 10000; //define constant variable of 10000 characters
void swap_characters_in_word (char *words, int start_of_word);	//declare function to reverse characters in words

int main(void)
{
	char words[SENTENCE_LENGTH]; //set word array
	int start_of_word = 0;
	
	printf("Please enter a sentence:\n"); //Ask for input
	fgets(words, SENTENCE_LENGTH, stdin); //Get sentence from user - NB fgets output ends with '\n' '\0'
	printf("You entered: %s\n", words); //(Check that program has stored user input)
	
	swap_characters_in_word(words, start_of_word);

	printf ("You Entered: %s\n", words); //print reversed words
	
	return 0; //All OK
}	//END Main

/********** FUNCTION TO REVERSE CHARACTERS IN WORDS **************/
void swap_characters_in_word (char *words, int start_of_word)
{	
	int counterPos = 0;
	int counterNeg = 0;
	int get_length;
	int end_of_word;
	char temporary;
	
	get_length = strlen(words); //Gets length of sentence
	words[get_length -1] = ' '; //replace '\n' with ' ' could alternatively loop through sentence until '\n' found and then replace it
	
	//Loop through sentence:
	for (counterPos = 0; words[counterPos] != '\0'; counterPos++) //run counter until '\0' reached in sentence
	{	
		//Get End and start of words entered
		if ((words[counterPos] == ' ') && (words[counterPos -1] != ' ')) //if positive counter reaches a space character in sentence:
		{	
			end_of_word = counterPos - 1;
			for (counterNeg = (counterPos - 1); words[counterNeg] != '\0' && words[counterNeg] != ' '; counterNeg--) //subtracts one from counterPos so that it's not a ' ', runs negative counter backwards until  it reaches '\0' or another ' ' character
			{
				start_of_word = counterNeg;
			}

			//change order of characters in word using the "temporary" char variable and another loop
			for (end_of_word = counterPos - 1; end_of_word >= start_of_word; end_of_word--)
			{
				temporary = words[end_of_word];
				words[end_of_word] = words[start_of_word];
				words[start_of_word] = temporary;
				start_of_word++;
			}
		}
	}
}
