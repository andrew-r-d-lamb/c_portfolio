/*************************************************************************************************

*Filename: sclTutor.c
*Authors: Andrew Lamb + Tutor
*Last Modified: 24/12/2012
*Description:	Program is a simple calculator that loops until user enters q to quit
				Suggestion for loop method provided by Tutor

*************************************************************************************************/
#include <stdio.h>

int main(void)
{
	char c;
	float a, b, sum;

	printf("Enter '+','-','*','/','q':\n");
	while ((c = getchar())!='q') //Get Character from User
	{
		/*Get Numbers from User*/
		printf("Enter First Number:");
		scanf("%10f",&a);
		printf("Enter Second Number:");
		scanf("%10f",&b);
		
		if (c == '+') 						//If this, then sum
		{	sum = a + b;			 		
			printf("The total is: %10f\n",sum); //Display total
		}
		else if (c == '-')  				//If this, then subtract
		{
			sum = a - b;
			printf("The total is: %10f\n",sum); //Display total
		}
		else if (c == '*')					//If this, then multiply
		{
			sum = a * b; 	
			printf("The total is: %10f\n",sum); //Display total
		}
		else if (c == '/') 					//If this, then divide
		{	 
			while (b == 0)
			{
				printf("\nUnable to divide by 0. Please enter new number to divide by:\n");
				scanf("%10f",&b);
			}
			sum = a / b;
			printf("The total is: %10f\n",sum);
		}
		printf("Enter '+','-','*','/','q':\n");
		c = getchar();
	}
		
	return 0;	//all OK
}