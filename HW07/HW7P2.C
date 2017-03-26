/*____________________________________________________________________________*/
/* HW07P2_141044030_Berkant_Erbey                                             */
/*                                                                            */
/* HW07P2.c                                                                   */
/* ____________                                                               */
/* Created on 15/04/2016 by Berkant Erbey                                     */
/*                                                                            */
/* Description                                                                */
/* ____________																  */
/*		The HW07P2.c contains the implementations of kickDisc,				  */
/*		randNumber,reflection and their helper functions					  */
/*____________________________________________________________________________*/
/*									Includes			                      */
/*____________________________________________________________________________*/
#include <stdlib.h> 		/*srand function definition*/
/*____________________________________________________________________________*/
/*									Defines  			                      */
/*____________________________________________________________________________*/
/*____________________________________________________________________________*/
/* 									Prototypes 								  */
/*____________________________________________________________________________*/

int randNumber(int angle);
/*____________________________________________________________________________*/
/* Parameters: Function takes one parameter.        						  */
/*     Angle>randNumber's input parameter   								  */
/*____________________________________________________________________________*/
/* Return Value: Function returns an integer.                                 */
/*     Randomize the angle value.										      */
/*____________________________________________________________________________*/
/* Description: int isPalindrome(char* str)                                   */
/*     This function checks the given string is palindrome or not             */
/*	   but you will match only letters,                                       */
/*	   Success-->1    Fail-->0 returns                                        */
/*____________________________________________________________________________*/
int reflection(int angle);
/*____________________________________________________________________________*/
/* Parameters: Function takes one parameter.        						  */
/*     angle->Disk's kicked angle   										  */
/*____________________________________________________________________________*/
/* Return Value: Function returns an integer.                                 */
/*     Calculates the reflection  angle + ((angle%11)-5)		 	          */
/*____________________________________________________________________________*/
/* Description:                                   						      */
/*     This function calculates the reflection of ball.Returns the angle      */
/*____________________________________________________________________________*/
int kickDisc(double wallWidth,double wallHeight,double ballCenterX,
	double kickAngle,double ballRadius,double goalWidth);
/*____________________________________________________________________________*/
/* Parameters: Function takes six parameters.        						  */
/*     wallWidth->	Table width								                  */
/*	   wallHeight-> Table wallHeight 										  */
/*     ballCenterX-> disc center distance from left side of Table 			  */
/*	   kickAngle  ->Disc kicked angle 										  */
/*	   ballRadius  ->Radius of ball 										  */
/*	   goalWidth   ->Width of goal Table          							  */
/* Return Value: Function returns an integer.                                 */
/*     If Given values ensure the goal condition  return 1,					  */
/*	   otherwise return 0.												      */
/*____________________________________________________________________________*/
/* Description:                                    							  */
/*     This function calls the reflection and any                             */
/*	   necessary helper functions to calculate the disc final location        */
/*	   is goal or not.                     									  */
/*	   Success-->1    Fail-->0 returns                                        */
/*____________________________________________________________________________*/


int randNumber(int angle)
{
	srand(angle);
	return rand();
}
int reflection(int angle)
{

	int resAngle;

	if(angle < 5)
	{
		angle = 5;
	}
	else if(angle > 175)
	{
		angle = 175;
	}
	else
	{
		resAngle = angle + randNumber((angle % 11) - 5);
	}

	return resAngle;

}
int kickDisc(double wallWidth,double wallHeight,double ballCenterX,
	double kickAngle,double ballRadius,double goalWidth)
{

	if(wallWidth <= 0 || wallHeight <= 0 || ballRadius <= 0 || goalWidth <= 0
			|| ballCenterX<0)
	{
		return 0;
	}
	else if(wallWidth <= goalWidth)
	{
		return 0;
	}

	if(ballCenterX == 0 && kickAngle == 90)
	{
		return 0;
	}





	return 0;




}
/*____________________________________________________________________________*/
/*								End of HW07P2.c								  */
/*____________________________________________________________________________*/