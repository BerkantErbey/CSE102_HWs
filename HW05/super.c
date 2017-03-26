#include <stdio.h>

void printBoard(char *board);
void initBoard(char board[]);

int main()
{
	char Dizi[64];

	initBoard(Dizi);
	printBoard(Dizi);

	printf("isupper(A)->%d\nislower(a)->%d",;


	return 0;


}
void initBoard(char board[]){
  
  int i;
  
  board[0]='r',board[1]='n',board[2]='b',board[3]='Q',board[4]=' ',board[5]=' ',board[6]='R',board[7]='r',
  board[8]=' ',board[9]=' ',board[10]=' ',board[11]=' ',board[12]='N',board[13]='n',board[14]='p',board[15]='p',
  board[16]='p',board[17]='p',board[18]=' ',board[19]=' ',board[20]=' ',board[21]='p',board[22]='p',board[23]='p',
  board[24]='p',board[25]=' ',board[26]=' ',board[27]=' ',board[28]='B',board[29]='p',board[30]=' ',board[31]='p',
  board[32]='p',board[33]=' ',board[34]=' ',board[35]=' ',board[36]=' ',board[37]=' ',board[38]='p',board[39]=' ',
  board[40]=' ',board[41]=' ',board[42]=' ',board[43]=' ',board[44]=' ',board[45]=' ',board[46]=' ',board[47]='p',
  board[48]=' ',board[49]=' ',board[50]=' ',board[51]=' ',board[52]=' ',board[53]='q',board[54]=' ',board[55]='p',
  board[56]=' ',board[57]=' ',board[58]=' ',board[59]=' ',board[60]='b',board[61]=' ',board[62]=' ',board[63]=' ';


 
}
void printBoard(char *board)
{
	int i;
	printf("   a  b  c  d  e  f  g  h\n");
	printf("   -  -  -  -  -  -  -  -\n");
	printf("8| ");
	for(i = 0; i <= 7;++i)
	{
		printf("%c  ",board[i] );
	}
	printf("|\n7| ");
	for (i = 8; i <= 15; ++i)
	{
		printf("%c  ",board[i] );
	}
	printf("|\n6| ");
	for (i = 16; i <= 23; ++i)
	{
		printf("%c  ",board[i] );
	}
	printf("|\n5| ");
	for (i = 24; i <= 31; ++i)
	{
		printf("%c  ",board[i] );
	}
	printf("|\n4| ");
	for (i = 32; i <= 39; ++i)
	{
		printf("%c  ",board[i] );
	}
	printf("|\n3| ");
	for (i = 40; i <= 47; ++i)
	{
		printf("%c  ",board[i] );
	}
	printf("|\n2| ");
	for (i = 48; i <= 55; ++i)
	{
		printf("%c  ",board[i] );
	}
	printf("|\n1| ");
	for (i = 56; i <= 63; ++i)
	{
		printf("%c  ",board[i] );
	}
	printf("|\n   -  -  -  -  -  -  -  -\n");
}