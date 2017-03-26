/*____________________________________________________________________________*/
/* HW06_141044030_Berkant_Erbey                                               */
/*                                                                            */
/* HW06P1.c                                                                   */
/* ____________                                                               */
/* Created on 09/04/2016 by Berkant_Erbey                                     */
/*                                                                            */
/* Description                                                                */
/* ____________																  */
/*		The HW06P1.c contains the implementations for function call           */
/*       freq                                                                 */
/*____________________________________________________________________________*/
/*									Includes			                      */
/*____________________________________________________________________________*/
#include <ctype.h>      /*For toupper definition*/
/*____________________________________________________________________________*/
/*							Function Prototypes                               */
/*____________________________________________________________________________*/
    /*calculate the character frequency of a given string*/
void freq(char* str,int* fr);
/*____________________________________________________________________________*/

void freq(char* str,int* fr)
{

	int i;                  /*Loop Control Variable*/
	char tempChar;          /*For store the converted upper chars*/

	for(i=0 ; i < 37; ++i)  /*Inıtialize frequence values to zero*/
	{
		fr[i]=0;
	}

	for(i=0; str[i] != '\0'; ++i)
	{
		/*For Letters*/
		if('A' <= str[i] && str[i] <= 'z')
		{
			tempChar = str[i];
			tempChar = toupper(tempChar);
			++fr[tempChar - 65];
		}
		/*For digits*/
		else if(('0' <= str[i]) && (str[i] <='9'))
		{
			++fr[26 + (str[i] - 48)];
		}
		/*Non-letter and non digit ascii characters*/
		else
		{
			++fr[36];
		}
	}

}
/*____________________________________________________________________________*/
/*								End of HW06P1.c								  */
/*____________________________________________________________________________*/