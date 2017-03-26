#include <stdio.h>
#include <math.h>
#define ROW 7
#define SIZE 6


void getInputs(int *num, int *borderWidth, char *borderChar);

int printNumber(int num,int borderWidth,char borderChar);

int findDigitNumber(int num);
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
	*num=0;
	*borderWidth=0;

	scanf("%d",num);
	scanf("%d",borderWidth);
	scanf(" %c",borderChar);
		
}

int printNumber(int num,int borderWidth,char borderChar)
{
	int i,k,digit,arr[SIZE];

	if((num>=0 && num<=99999) && borderWidth>=0)
	{
		digit=findDigitNumber(num);
		for(i=digit;i>=1;--i)
		{	k=pow(10.0,i);
			arr[i]=(num%k)/pow(10.0,(i-1));
			printf("%d\n",arr[i]);
		}

		upDown (num,borderWidth,borderChar,digit);	
		middle (num,borderWidth,borderChar,digit);

		/*1. satir*/
		frame(borderWidth,borderChar);
		for(i=digit;i>=1;--i)
		{
			if(arr[i]==1)
			printf("   %c   ",borderChar);
			else if(arr[i]==4)
			printf("  %c %c  ",borderChar,borderChar);
			else
			printf("  %c%c%c  ",borderChar,borderChar,borderChar);
		}
		/*1.satir sonu*/
		frame(borderWidth,borderChar);
		printf("\n");

		frame(borderWidth,borderChar);

		for(i=digit;i>=1;--i)
		{
			if(arr[i]==1)
			printf("  %c%c   ",borderChar,borderChar);
			else if((arr[i]==2)||(arr[i]==3)||(arr[i]==7))
			printf("    %c  ",borderChar);
			else if((array[i]==4)||(arr[i]==8)||(arr[i]==9)||(arr[i]==0))
			printf("  %c %c  ",borderChar,borderChar);
			else
			printf("  %c    ",borderChar);
		}
		frame(borderWidth,borderChar);
		printf("\n");	

		frame(borderWidth,borderChar);
		for(i=digit;i>=1;--i)
		{	
			if(arr[i]==1)
			printf("   %c   ",borderChar);	
			else if(arr[i]==3)
			printf("   %c%c  ",borderChar,borderChar);
			else if(arr[i]==7)
			printf("    %c  ",borderChar);
			else if(arr[i]==0)
			printf("  %c %c  ",borderChar,borderChar);
			else
			printf("  %c%c%c  ",borderChar,borderChar,borderChar);
		}
		frame(borderWidth,borderChar);
		printf("\n");

		frame(borderWidth,borderChar);
		for(i=digit;i>=1;--i)
		{	
			if(arr[i]==1)
			printf("   %c   ",borderChar);	
			else if(arr[i]==2)
			printf("  %c    ",borderChar);
			else if(arr[i]==6||arr[i]==8||arr[i]==0)
			printf("  %c %c  ",borderChar,borderChar);
			else
			printf("    %c  ",borderChar);
		}
		frame(borderWidth,borderChar);
		printf("\n");

		frame(borderWidth,borderChar);
		for(i=digit;i>=1;--i)
		{	
			if(arr[i]==4||arr[i]==7)
			printf("    %c  ",borderChar);	
			else
			printf("  %c%c%c  ",borderChar,borderChar,borderChar);
		}
		frame(borderWidth,borderChar);
		printf("\n");

		middle (num,borderWidth,borderChar,digit);
		upDown (num,borderWidth,borderChar,digit);
		return 1;
	}
	else
	return 0;
	
}

int findDigitNumber(int num)
{
	int digitnumber;

	for(digitnumber=1;num>=10;++digitnumber)
	{	num/= 10;	}

	return digitnumber;
}

void upDown (int num, int borderWidth,char borderChar,int digit)
{
	int i,k;

	for(k=0;k<borderWidth;++k)
	{
		for(i=0;i<(digit*ROW+2*borderWidth);++i)
		{	printf("%c",borderChar);	}
		printf("\n");
	}
}
void middle (int num,int borderWidth,char borderChar,int digit)
{
	int k;

	for(k=0;k<borderWidth;++k)
	{	printf("%c",borderChar);	}
	for(k=0;k<digit*ROW;++k)
	{	printf(" ");	}
	for(k=0;k<borderWidth;++k)
	{	printf("%c",borderChar);	}
	printf("\n");
}
void frame(int borderWidth,char borderChar)
{
	int k;
	for(k=0;k<borderWidth;++k)
	{	printf("%c",borderChar);	}
}
