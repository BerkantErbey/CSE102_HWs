/*____________________________________________________________________________*/
/* HW07P1_141044030_Berkant_Erbey                                             */
/*                                                                            */
/* HW07P1.c                                                                   */
/* ____________                                                               */
/* Created on 15/04/2016 by Berkant Erbey                                     */
/*                                                                            */
/* Description                                                                */
/* ____________																  */
/*		The HW07P1.c contains the implementations of isPalindrome 			  */
/*		function for function calls(recursivePalindrome,deleteLastElement)    */
/*____________________________________________________________________________*/
/*									Includes			                      */
/*____________________________________________________________________________*/
#include <string.h>		/*For strlen definition*/
#include <math.h>		/*For abs definition*/
#include <stdio.h>    .
/*____________________________________________________________________________*/
/*									Defines  			                      */
/*____________________________________________________________________________*/
#define STRSIZE 256    /*For the letters string size*/
/*____________________________________________________________________________*/
/* 									Prototypes 								  */
/*____________________________________________________________________________*/
int isPalindrome(char* str);
/*____________________________________________________________________________*/
/* int isPalindrome(char* str)												  */
/*____________________________________________________________________________*/
/* Parameters: Function takes one parameter.        						  */
/*     str ->String Parameters   											  */
/*____________________________________________________________________________*/
/* Return Value: Function returns an integer.                                 */
/*     If Given string is a palindrome return 1                               */
/*	   otherwise return 0.												      */
/*____________________________________________________________________________*/
/* Description: int isPalindrome(char* str)                                   */
/*     This function checks the given string is palindrome or not             */
/*	   but you will match only letters,                                       */
/*	   Success-->1    Fail-->0 returns                                        */
/*____________________________________________________________________________*/
int recursivePalindrome(char* string);
/*____________________________________________________________________________*/
/* Parameters: Function takes one Parameters     					          */
/*     string: String variable						                          */
/*____________________________________________________________________________*/
/* Return Value: Function returns 0 or any positive value                     */
/*     			Success-->Positive value Fail-->0 							  */
/*____________________________________________________________________________*/
/* Description: This function recursivePalindrome is                          */
/*		isPalindrome's wrappers function.It checks given string               */
/*		palindrome or not, recursively.			                              */
/*____________________________________________________________________________*/
void deleteLastElement(char* string);
/*____________________________________________________________________________*/
/* Parameters: Function takes one Parameters     					          */
/*     string: String variable						                          */
/*____________________________________________________________________________*/
/* Return Value: String which its deleted last element                        */
/*____________________________________________________________________________*/
/* Description: This function deleteLastElement is  deletes the last          */
/*		element of given string.                                              */
/*____________________________________________________________________________*/


int isPalindrome(char *str)
{	
	int ans=0;				/*Return value*/
	int i,j=0; 				/*Index Values*/
	char letters[STRSIZE];	/*For store the letters*/

	if(str[0]=='\0')
	{
		ans = 0;
	}

	for(i = 0; str[i]!='\0';++i)
	{
		if( ((str[i] >= 'A' && str[i] <='Z') || (str[i] >='a' && str[i]<='z'))
		    && (str[i]!=' ' && str[i+1])!= ' ' )
		{
			letters[j] =str[i];
			++j;
		}
	}
	

	if(letters[0]=='\0')		/*Checks the letters string empty or not*/
	{
		ans = 0;
	}

	else if(recursivePalindrome(letters))
	{
		ans = 1;
	}

	return ans;
}
int recursivePalindrome(char* string)
{
	int ans=0;				/*Return Value*/
	int size;				/*For length */

	size = strlen(string);

	if(string[0]=='\0')
	{
		ans = 0;
	}
	else if((string[0]==string[size-1]) || abs(string[0]-string[size-1]) == 32 )
	{
		deleteLastElement(string);
		ans = 1 + recursivePalindrome(&string[1]);
	}

	return ans;

}
void deleteLastElement(char* string)
{

	int length;

	length = strlen(string);

	string[length - 1] = '\0';

}
/*____________________________________________________________________________*/
/*								End of HW07P1.c								  */
/*____________________________________________________________________________*/
