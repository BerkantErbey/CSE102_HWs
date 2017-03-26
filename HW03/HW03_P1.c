/*____________________________________________________________________________*/
/* HW03_141044030_Berkant_Erbey                                               */
/*                                                                            */
/* HW03.c                                                                     */
/* ____________                                                               */
/* Created on 05/03/2016 by Berkant_Erbey                                     */
/*                                                                            */
/* Description                                                                */
/* ____________																  */
/*		The HW03.c contains the implementations of main function for          */
/*		function calls(factorialNumber,oddNumber,narcissisticNumber,findDigit)*/
/*____________________________________________________________________________*/
/*									Includes			                      */
/*____________________________________________________________________________*/
#include <stdio.h> 		/*For printf,scanf definitions*/
#include <math.h>  		/*For pow definition*/
/*____________________________________________________________________________*/
/*									Defines									  */
/*____________________________________________________________________________*/
#define DIVTEN 10 		/*For Dividing 10*/
#define REMTEN 10 		/*For Remaining 10*/
/*____________________________________________________________________________*/
/*____________________________________________________________________________*/
/*							Function Prototypes                               */
/*____________________________________________________________________________*/
	
	/*Checks the number is factorial or not factorial*/
void factorialNumber(int number);
	
	/*Checks the number is odd or not odd*/
void oddNumber(int number);

	/*Checks the number is narcissistic or not narcissistic*/
void narcissisticNumber(int number);
	
	/*Calculate the how many digit in number.Returns the digit number.*/
int findDigit(int number);

/*____________________________________________________________________________*/
int main(void)
{
	/*For given number from user*/
	int number;			
	/*Which control to be used*/
	int choice;	
	/*For user's choice yes or no*/		
	char button;



	printf("*************************************************\n");
	printf("*                   WELCOME!                    *\n");
	printf("*This program checks whether the given number   *\n");
	printf("*is an odd, a factorial or narcissistic number  *\n");
	printf("*                                               *\n");
	printf("*************************************************\n");

	do
	{
		printf("Please enter a positive integer : ");
		scanf("%d",&number);

		if(number <= 0)
		{
			printf("The entered number is not positive.");
		}
		
		if(number > 0)
		{
			printf("Which property would you like to check?\n");
			printf("1)Odd number\n2)Factorial number\n3)Narcissistic number\n");
			printf("Please enter(1/2/3): ");
			scanf("%d",&choice);
			
			if(choice == 1)
			{
				oddNumber(number);
			}
			else if(choice == 2)
			{
				factorialNumber(number);
			}
			else if(choice == 3)
			{
				narcissisticNumber(number);
			}
	
		}
		printf("Do you want to continue(y/n)? ");
		scanf(" %c",&button);
	}
	while((button == 'y' || button == 'Y') && (button!='N' || button!='n'));


	return 0;
}
void oddNumber(int number)
{

	if((number%2)==1)
	{
		printf("%d is an odd number !\n",number);
	}
	else
	{
		printf("%d is not an odd number !\n",number);
	}

}
void factorialNumber(int number)
{
	/*Loop control variable*/
	int factor;	

	int product = 1;

	for(factor=1; (product) < number; ++factor)
	{
		product *= factor;
	}

	if(product == number)
	{
		printf("%d is a factorial number !\n",number);
	}
	else
	{
		printf("%d is not a factorial number !\n",number);		
	}

}
void narcissisticNumber(int number)
{
	/*Calculated number*/
	int calcNum;		
	/*Number stored in temp variable*/
	int temp;	

	int remaining;		
	
	calcNum = 0; 			
	
	temp = number;

	while(temp>0)
	{
		remaining = temp % REMTEN;
		temp /= DIVTEN;
		calcNum += pow(remaining,findDigit(number));
	}
	if(calcNum == number)
	{
		printf("%d is a narcissistic number !\n",number);
	}
	else
	{
		printf("%d is not a narcissistic number !\n",number);
	}

}
int findDigit(int number)
{

	int digitNumber = 1;

	while((number / DIVTEN) > 0)
	{
		number /= DIVTEN;
		digitNumber++;
	}	

	return digitNumber;
}
/*____________________________________________________________________________*/
/*								End of HW03.c								  */
/*____________________________________________________________________________*/
