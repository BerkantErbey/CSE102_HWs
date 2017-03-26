/*____________________________________________________________________________*/
/*                                                                            */
/* HW01_141044030_Berkant_Erbey                                               */
/*                                                                            */
/* main.c                                                                     */
/* ___________                                                                */
/* Created on 21/02/2016 by Berkant_Erbey                                     */
/*                                                                            */
/* Description                                                                */
/* ____________                                                               */
/*		The main.c contains the implementations of main function              */ 
/*      for the second part of the homework I, which are used for             */
/*		calculating overall grade for student                                 */

/*____________________________________________________________________________*/
/*									Includes			                      */
/*____________________________________________________________________________*/
#include <stdio.h>		/*printf,scanf definitions*/

/*____________________________________________________________________________*/
/*									Defines 			                      */
/*____________________________________________________________________________*/
#define DaysPerYear 365  /*Constant macros for Earth*/
#define DaysPerMonth 30
#define HoursPerDay 24

int main(void)
{
	
	int currYear,currMonth,currDay;	/*Current date parameters*/

	int brthYear,brthMonth,brthDay; /*Birthdate parameters*/

	int totalDay,totalHour;			/*Total time for Earth*/

	int plntHour,plntDay,plntMonth; /*Time parameters of another planet*/
	
	int ageYears,ageMonths,ageDays; /*Age values for another planet*/
	

	/*User entry the inputs*/
	
	printf("Please enter the current date.\n");
	printf("Year:");
	scanf("%d",&currYear);
	
	printf("Month:");
	scanf("%d",&currMonth);

	printf("Day:");
	scanf("%d",&currDay);

	printf("Please enter your birthday.\n");
	printf("Year:");
	scanf("%d",&brthYear);

	printf("Month:");
	scanf("%d",&brthMonth);

	printf("Day:");
	scanf("%d",&brthDay);

	totalDay=((currYear - brthYear)* DaysPerYear)+
			((currMonth - brthMonth)* DaysPerMonth)+(currDay - brthDay);

	printf("You have lived %d days.\n",totalDay);

	printf("Please enter about the time of another planet\n");
	
	printf("How many hours is a day?");
	scanf("%d",&plntHour);
	
	printf("How many days is a month?");
	scanf("%d",&plntDay);
	
	printf("How many months is a year?");
	scanf("%d",&plntMonth);
	

	/*Calculation part*/
	totalHour =	totalDay * HoursPerDay;
	
	ageYears  =  totalHour / (plntHour * plntDay * plntMonth);
	
	ageMonths = (totalHour -(ageYears * plntHour * plntDay * plntMonth))
	/ (plntHour * plntDay);
	
	ageDays   = ((totalHour- (ageYears * plntHour * plntDay * plntMonth))-
	(plntHour * plntDay * ageMonths)) / (plntHour);

	/*Display the calculated infos*/
	printf("If you lived in a planet where a day is %d hours, a month is %d "
	    "days and a year is %d months: you were %d years, %d months and "
	    "%d days old\n",plntHour,plntDay,plntMonth,ageYears,ageMonths,ageDays);
	
	
	return 0;
}
/*____________________________________________________________________________*/
/*								End of main.c								  */
/*____________________________________________________________________________*/
