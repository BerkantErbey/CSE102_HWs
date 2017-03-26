/*____________________________________________________________________________*/
/* HW02_141044030_Berkant_Erbey                                               */
/*                                                                            */
/* Part2.c                                                                    */
/* ____________                                                               */
/* Created on 25/02/2016 by Berkant_Erbey                                     */
/*                                                                            */
/* Description                                                                */
/* ____________																  */
/*		The Part2.c contains the implementations of main function for         */
/*		function calls(area and perimeter calculation for geometric shapes)   */
/*      and area-perimeter calculation functions.                             */
/*		                                                                      */
/*____________________________________________________________________________*/
/*									Includes			                      */
/*____________________________________________________________________________*/

#include <stdio.h>
/*____________________________________________________________________________*/
/*									Defines									  */
/*____________________________________________________________________________*/
#define PI 3.14

/*____________________________________________________________________________*/
/*____________________________________________________________________________*/
/*							Function Prototypes                               */
/*____________________________________________________________________________*/

					/*Calculate the perimeter of Rectangle*/
int perimeterOfRectangle(int width,int height); 
					/*Calculate the area of Rectangle*/
int areaOfRectangle(int width,int height);
					/*Calculate the perimeter of Square*/
int perimeterOfSquare(int width);
					/*Calculate the area of Square*/
int areaOfSquare(int width);
					/*Calculate the perimeter of Circle*/
double perimeterOfCircle(int radius);
					/*Calculate the area of Circle*/
double areaOfCircle(int radius);
/*____________________________________________________________________________*/

int main(void)
{

	int width,height,radius;

	/*Rectangle perimeter and area calculation*/
	printf("Please enter the width of the rectangle:");
	scanf("%d",&width);

	printf("Please enter the height of the rectangle:");
	scanf("%d",&height);

	printf("The area of the rectangle is: %d\n",areaOfRectangle(width,height));
	printf("The perimeter of rectangle is: %d\n"
			,perimeterOfRectangle(width,height));

	/*Square perimeter and area calculation*/
	printf("Please enter the width of the square: ");
	scanf("%d",&width);

	printf("The area of square is: %d\n",areaOfSquare(width));
	printf("The perimeter of square is: %d\n",perimeterOfSquare(width));


	/*Circle*/
	printf("Please enter the radius of circle:");
	scanf("%d",&radius);
	
	printf("The area of the circle is: %d\n",areaOfCircle(radius));
	printf("The perimeter of circle is: %d\n",perimeterOfCircle(radius));	

	return 0;
}
int perimeterOfRectangle(int width,int height)
{
	return (2*(width+height));
}
int areaOfRectangle(int width,int height)
{
	return (width*height);
}
int perimeterOfSquare(int width)
{
	return (width*4);
}
int areaOfSquare(int width)
{
	return (width*width);
}
double perimeterOfCircle(int radius)
{
	return (2*PI*radius);
}
double areaOfCircle(int radius)
{
	return (PI*radius*radius);
}
/*____________________________________________________________________________*/
/*								End of Part2.c                                */
/*____________________________________________________________________________*/
