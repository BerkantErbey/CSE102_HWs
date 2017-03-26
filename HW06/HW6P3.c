/*____________________________________________________________________________*/
/* HW06_141044030_Berkant_Erbey                                               */
/*                                                                            */
/* HW06P3.c                                                                   */
/* ____________                                                               */
/* Created on 09/04/2016 by Berkant_Erbey                                     */
/*                                                                            */
/* Description                                                                */
/* ____________																  */
/*		The HW06P3.c contains the implementations for function call           */
/*       matcher and count                                                    */
/*____________________________________________________________________________*/
/*									Includes			                      */
/*____________________________________________________________________________*/
#include <string.h>         /*For strlen definition*/
/*____________________________________________________________________________*/
/*							Function Prototypes                               */
/*____________________________________________________________________________*/
/*                                                                            */
/*      Function for finding substring(s) in a given string.                  */
/*      Instead of matching the exact substring, you are asked to             */
/*      match only odd indexed characters                                     */
char* matcher(char* haystack,char* needle);
/*      Function that counts the occurrences of a substring                   */
/*      in the a given string using the matcher function                      */
int count(char* str,char* substr);
/*____________________________________________________________________________*/

char *matcher(char* haystack,char* needle)
{
	int i,j=0,sizeN,sizeH;
	int rValue;/*For return value*/ 
	int increaser = 0;/*Increment variable for odd indexs*/
	int matched = 0; 	/*Counts matched character*/

    /*If given strings \0 return NULL*/
	if(haystack[0]=='\0' || needle[0]=='\0')
	{
		return NULL;
	}

	sizeN = strlen(needle);
	sizeH = strlen(haystack);
    
    /*If needle's size bigger than haystacks return NULL*/
	if(sizeN > sizeH)
	{
		return NULL;
	}

	for(i=0; haystack[i] != '\0'; ++i)
	{
		if(haystack[i] == needle[j])
		{
			rValue = i;     /*First occurence index,for the return*/
			increaser+=2;
			++matched;
			for(j = 2;j <= sizeN-1; j+=2)
			{
				if(haystack[i+increaser] == needle[j])
				{
					++matched;
				}
				increaser += 2;
			}
			if(matched == (sizeN - 2))
				return &haystack[rValue];
            
            /*After the loop,initialization to beginning value*/
			increaser = 0; 
			matched = 0;
			j = 0;
		}
	}

	return NULL;
}
int count(char* str,char* substr)
{
    int i,count = 0;
    char* res;
	for(i=0; str[i]!='\0'; ++i)
 	{
  		res = &(matcher(&str[i], substr));
  		if(res != NULL)
  		{
   			++count;
  		}
 	}

 return count;
}
/*____________________________________________________________________________*/
/*								End of HW06.c								  */
/*____________________________________________________________________________*/