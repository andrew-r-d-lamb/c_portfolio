/*************************************************************************************************

*Filename: whileloop10000.c
*Authors: Andrew Lamb
*Last Modified: 24/12/2012
*Description:	Program initialises a char as a byte.
				Loop runs 10000 times - what's largest value output?
				(Loop cycles around from -128 to 127)

*************************************************************************************************/

#include <stdio.h>

/*whileloop10000.c - Loop runs 10000 times - what's largest value output?
Authors: Andrew Lamb
Last Modified: 12/11/2012
*/

int main(void)
{
	char as_a_byte = 0;
	int counter = 0;

	printf ("%d\n",as_a_byte);
	while (counter < 10000)	//loop starts at 0 and counts up to last value before 10000
	{
		as_a_byte = as_a_byte + 1; 
		printf ("%d: %d\n", counter, as_a_byte); //counter printed as a check
		counter++; //could be written: counter = counter + 1;
	}
	return 0;	//all OK
}