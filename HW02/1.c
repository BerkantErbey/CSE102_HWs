/*____________________________________________________________________________*/
/*                                                                            */
/* HW02_141044030_Berkant_Erbey                                               */
/*                                                                            */
/* Part1.c                                                                    */
/* ____________                                                               */
/* Created on 25/02/2016 by Berkant_Erbey                                     */
/*                                                                            */
/* Description                                                                */
/* ____________																  */
/*		The Part1.c contains the implementations of main function             */ 
/*      for function call(calculateLastGrade),and calculateLastGrade          */
/*		which are used for calculating overall grade for student              */
/*____________________________________________________________________________*/
/*									Includes			                      */
/*____________________________________________________________________________*/
#include <stdio.h>					/*printf,scanf definitions*/

/*____________________________________________________________________________*/
/*							Function Prototype                                */
/*____________________________________________________________________________*/
void calculateLastGrade();	/*Calculate the student's overall grade*/

/*____________________________________________________________________________*/

int main(void)
{

	void calculateLastGrade();
	void calculateLastGrade();
	void calculateLastGrade();
	
	return 0;
}
void calculateLastGrade()
{
	double mtWeight,mtGrade; 		/*Midterm weight and grade*/
	double hwWeight,hwGrade; 		/*Homework weight and grade*/
	double fnlWeight,fnlGrade;		/*Final weight and grade*/

	double totalGrade;				/*Overall grade*/
	
	/*User entry the inputs*/
	printf("Please enter the 1. midterm weight:");
	scanf("%lf",&mtWeight);

	printf("Please enter the 1. homework weight:");
	scanf("%lf",&hwWeight);
	
	printf("Please enter the final exam weight:");
	scanf("%lf",&fnlWeight);

	printf("Please enter the 1. midterm grade:");
	scanf("%lf",&mtGrade);

	printf("Please enter the 1. homework grade:");
	scanf("%lf",&hwGrade);

	printf("Please enter the final exam grade:");
	scanf("%lf",&fnlGrade);
	
	/*Calculating overall grade*/
	totalGrade = (mtWeight * mtGrade)/100+(hwWeight * hwGrade)/100+
				(fnlWeight * fnlGrade)/100;
	
	/*Display the overall grade*/
	printf("Your final grade is: %f\n",totalGrade);

}
/*____________________________________________________________________________*/
/*								End of Part1.c								  */
/*____________________________________________________________________________*/
