#include <stdio.h>

#define MIN_LIM 0
#define MAX_LIM 100000

void getInputs(int *num, int *borderWidth, char *borderChar);

int printNumber(int num,int borderWidth,char borderChar);

int howManyDigit(int num);

double pow(double x,double y);

void upDown (int num, int borderWidth,char borderChar,int digit);

void middle (int num,int borderWidth,char borderChar,int digit);

void frame(int borderWidth,char borderChar);


int main()
{
	int num,borderWidth;
	char borderChar;

	getInputs(&num,&borderWidth,&borderChar);
	printNumber(num,borderWidth,borderChar);

	return 0;
}
void getInputs(int* num, int* borderWidth, char* borderChar)
{
	
	scanf("%d%d %c",num,borderWidth,borderChar);
		
}
int printNumber(int num,int borderWidth,char borderChar)
{
	int lcv1,lcv2,digitNum,arr[SIZE];

	if(num >= MIN_LIM && num < MAX_LIM && borderWidth >= 0)
	{
		digitNum = howManyDigit(num);
		
		for(lcv1 = digit ; i >= 1 ; --i)
		{	
			k = pow(10,lcv1);
			arr[lcv1] = (num%lcv2)/pow(10,(lcv1 - 1) );
			printf("%d\n",arr[lcv1]);
		}

		upDown (num,borderWidth,borderChar,digitNum);	
		middle (num,borderWidth,borderChar,digitNum);

		/*1. satir*/
		frame(borderWidth,borderChar);
		for(lcv1 = digit; lcv1 >= 1; --lcv1)
		{
			if(arr[lcv1]==1)
			printf("   %c   ",borderChar);
			else if(arr[lcv1]==4)
			printf("  %c %c  ",borderChar,borderChar);
			else
			printf("  %c%c%c  ",borderChar,borderChar,borderChar);
		}
		/*1.satir sonu*/
		frame(borderWidth,borderChar);
		printf("\n");

		frame(borderWidth,borderChar);

		for(lcv1 = digitNum; lcv1 >= 1; --lcv1)
		{
			if(arr[lcv1ilcv1] == 1)
			{
				printf("  %c%c   ",borderChar,borderChar);
			}
			else if((arr[lcv1] == 2) || (arr[lcv1] == 3) || (arr[lcv1] == 7) )
			{
				printf("    %c  ",borderChar);
			}
			else if( (array[lcv1] == 4) || (arr[lcv1] == 8) || (arr[lcv1] == 9) || (arr[lcv1] == 0) )
			{
				printf("  %c %c  ",borderChar,borderChar);
			}
			else
			{
				printf("  %c    ",borderChar);
			}
	
		}
		
		frame(borderWidth,borderChar);
		printf("\n");	
		frame(borderWidth,borderChar);
		
		for(lcv1 = digit; lcv1 >= 1; --lcv1)
		{	

			if(arr[lcv1] == 1)
			{
				printf("   %c   ",borderChar);
			}	
			else if(arr[lcv1] == 3)
			{
				printf("   %c%c  ",borderChar,borderChar);
			}
			else if(arr[i]==7)
			{
				printf("    %c  ",borderChar);
			}
			else if(arr[i]==0)
			{
				printf("  %c %c  ",borderChar,borderChar);
			}
			else
			{
				printf("  %c%c%c  ",borderChar,borderChar,borderChar);
			}

		}

		frame(borderWidth,borderChar);
		printf("\n");
		frame(borderWidth,borderChar);

		for(lcv1 = digitNum; lcv1 >= 1; --lcv1)
		{	
		
			if(arr[lcv1] == 1)
			{
				printf("   %c   ",borderChar);	
			}
			else if(arr[i] ==	 2)
			{
				printf("  %c    ",borderChar);
			}
			else if(arr[i]==6||arr[i]==8||arr[i]==0)
			{
				printf("  %c %c  ",borderChar,borderChar);
			}
			else
			{
				printf("    %c  ",borderChar);
			}
	
		}
		
		frame(borderWidth,borderChar);
		printf("\n");
		frame(borderWidth,borderChar);
		
		for(lcv1 = digit; lcv1 >= 1; --lcv1)
		{	
		
			if(arr[lcv1] == 4 || arr[lcv1] == 7)
			{
				printf("    %c  ",borderChar);	
			}
			else
			{
				printf("  %c%c%c  ",borderChar,borderChar,borderChar);
			}
		
		}
		
		frame(borderWidth,borderChar);
		printf("\n");

		middle (num,borderWidth,borderChar,digit);
		upDown (num,borderWidth,borderChar,digit);
		
		return 1;
	}
	else
	{
		return 0;
	}
	
}
int howManyDigit(int num)
{
	
	int digitNum = 1;

	while(num >= 10)
	{	
		num/= 10;
	}

	return digitNum;
}
double pow(double x,double y)
{

	double resP = 1;
	int lcv = 0;

	while( lcv < y )
	{
		resP*=x;
		++lcv;
	}

	return resP;
}
void upDown (int num, int borderWidth,char borderChar,int digit)
{
	int lcv1,lcv2;

	for(lcv1 = 0; lcv1 < borderWidth; ++lcv1)
	{
		
		for(lcv2 = 0; lcv2 < (digit * ROW + (2 * borderWidth) ); ++lcv2)
		{	
			printf("%c",borderChar);	
		}
		
		printf("\n");
	
	}

}
void middle (int num,int borderWidth,char borderChar,int digit)
{

	int lcv;

	for(lcv=0; lcv < borderWidth; ++lcv)
	{	
		printf("%c",borderChar);	
	}
	
	for(lcv=0; lcv < digit*ROW; ++lcv)
	{	
		printf(" ");	
	}
	lcv 
 	for(lcv = 0; lcv < borderWidth; ++lcv)
	{	
		printf("%c",borderChar);	
	}
	printf("\n");

}
void frame(int borderWidth,char borderChar)
{

	int lcv;
	for(lcv = 0; lcv < borderWidth; ++lcv )
	{	
		printf("%c",borderChar);
	}

}