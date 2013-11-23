/*************************************************************************************************

*Filename: secondMain.c
*Authors: Peter Cahill, Andrew Lamb
*Last Modified: 24/12/2012
*Description:	Example of the second main() - copied from L5 Slide 28

*************************************************************************************************/

#include <stdio.h>

int main (int argc, char *argv[])	//command line arguments.  int argc counts number of arguments. char *argv[] stores arguments in an array
{
	int i;
	
	printf ("You supplied %d arguments\n", argc);	//display number of arguments

	for (i = 0; i < argc; i++) printf ("argument %d = %s\n", i, argv[i]);	//display argument number and argument

	return 0;
}