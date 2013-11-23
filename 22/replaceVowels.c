/*************************************************************************************************

*Filename: replaceVowels.c
*Authors: Andrew Lamb
*Last Modified: 24/12/2012
*Description:	Program replaces vowels from user-input with $ signs

*************************************************************************************************/

#include <stdio.h>
#include <string.h>

const int SENTENCE_LENGTH = 10000;

int main(void)
{
	char sentence[SENTENCE_LENGTH];
	int count = 0;

	printf("Please Enter a Sentence:\n");
	fgets(sentence, SENTENCE_LENGTH, stdin);
	printf("You Entered:%s", sentence);

		for (count = 0; sentence[count] != '\n' && sentence[count] != '\0'; count++) //counter
		{	//replaces a,e,i,o,u with $
			if (sentence[count] == 'a' || sentence[count] == 'e' || sentence[count] == 'i' || sentence[count] == 'o' || sentence[count] == 'u')
			{
				sentence[count] = '$';
			}
		}
	
	printf("You Entered:%s", sentence);

	return 0;	//all OK
}