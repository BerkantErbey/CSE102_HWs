/*____________________________________________________________________________*/
/*                                                                            */
/* HW01_141044030_Berkant_Erbey                                               */
/*                                                                            */
/* main.c                                                                     */
/* ____________                                                               */
/* Created on 20/02/2016 by Berkant_Erbey                                     */
/*                                                                            */
/* Description                                                                */
/* ____________																  */
/*		The main.c contains the implementations of main function              */ 
/*      for the first part of the homework I, which are used for              */
/*		calculating overall grade for student                                 */
/*____________________________________________________________________________*/
/*									Includes			                      */
/*____________________________________________________________________________*/
#include <stdio.h>		/*printf,scanf definitions*/

int main(void)
{
	
	double mt1Weight,mt2Weight,mt3Weight;  /*Weights of midterms*/
	double hw1Weight,hw2Weight;				/*Weights of homeworks*/
	double fnlWeight;						/*Final weight*/

	double mt1Grade,mt2Grade,mt3Grade;	/*Grades of midterms*/   
	double hw1Grade,hw2Grade;			/*Grades of homeworks*/
	double fnlGrade;					/*Grade of final*/

	double totalMt,totalHw,totalFnl,totalGrade;

	
	/*User entry weights and grades*/
	printf("Please enter the 1. midterm weight:");
	scanf("%lf",&mt1Weight);
	
	printf("Please enter the 2. midterm weight:");
	scanf("%lf",&mt2Weight);
	
	printf("Please enter the 3. midterm weight:");
	scanf("%lf",&mt3Weight);

	printf("Please enter the 1. homework weight:");
	scanf("%lf",&hw1Weight);

	printf("Please enter the 2. homework weight:");
	scanf("%lf",&hw2Weight);

	printf("Please enter the final exam weight:");
	scanf("%lf",&fnlWeight);


	printf("Please enter the 1. midterm grade:");
	scanf("%lf",&mt1Grade);

	printf("Please enter the 2. midterm grade:");
	scanf("%lf",&mt2Grade);

	printf("Please enter the 3. midterm grade:");
	scanf("%lf",&mt3Grade);

	printf("Please enter the 1. homework grade:");
	scanf("%lf",&hw1Grade);

	printf("Please enter the 2. homework grade:");
	scanf("%lf",&hw2Grade);

	printf("Please enter the final exam grade:");
	scanf("%lf",&fnlGrade);
	
	/*Calculation part*/

	totalMt    =(mt1Weight * mt1Grade)/100 +(mt2Weight*mt2Grade)/100
				+(mt3Weight * mt3Grade)/100;

	totalHw    =(hw1Weight * hw1Grade)/100 +(hw2Weight * hw2Grade)/100;

	totalFnl   =(fnlGrade * fnlWeight)/100;

	totalGrade = totalMt + totalHw + totalFnl;

	/*Display the overall grade*/

	printf("Your final grade is: %f\n",totalGrade);
	
	return 0;

}
/*____________________________________________________________________________*/
/*								End of main.c								  */
/*____________________________________________________________________________*/
