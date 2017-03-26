#include <stdio.h>
#include <ctype.h>


void initBoard(char board[]);
void getPosition(char *col,int *row);
int isValidCell(char col,int row);
void printBoard(char *board);

int isPieceMovable(char *board);

int isRookMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow);
int isKnightMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow);
int isBishopMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow);
int isKingMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow);
int isQueenMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow);
int isPawnMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow);
char whichPiece(char sourceCol,char SourceRow);
int coordinateFinder(char col,int row);
int colorFinder(char *board,int sourcePoint,int targetPoint);
/*Hangi tas olduğunu bulsun,switch caselede o fonksiyonu is piece movable a dondursun*/




void getPosition(char *col,int *row)
{

		
		scanf(" %c%d",col,row);

}
int isValidCell(char col,int row)
{
	
	if( ( col >= 'a' && col <= 'h' ) && ( row >= 1 && row <= 8 ) )
	{
		return 1;
	}	
	else
	{
		return 0;
	}

}

int isPieceMovable(char *board)
{
	char sColumn,tColumn;
	int sRow,tRow;
	/*int sourceColumn,targetColumn;*//*For colums num stored in this variable*/
	char chessPiece;/**/

	int s;

	getPosition(&sColumn,&sRow);
	
	getPosition(&tColumn,&tRow);
	

	if( ((isValidCell(sColumn,sRow))==0 ) || (isValidCell(tColumn,tRow)) == 0)
	{
		return 0;
	}
	
	s = coordinateFinder(sColumn,sRow);/*Inıtialization to source point*/
	chessPiece = board[s];
    
    
    if(chessPiece == 'r' || chessPiece == 'R')
    {
       	if(isRookMovable(board,sColumn,sRow,tColumn,tRow))
		{
			return 1;
		}
		return 0;
    }
    if(chessPiece == 'n' || chessPiece == 'N')
    {
       	if(isKnightMovable(board,sColumn,sRow,tColumn,tRow))
		{
			return 1;
		}
		return 0;
    }
    if(chessPiece == 'b' || chessPiece == 'B')
    {
       	if(isBishopMovable(board,sColumn,sRow,tColumn,tRow))
		{
			return 1;
		}
		return 0;
    }
    if(chessPiece == 'k' || chessPiece == 'K')
    {
       	if(isKingMovable(board,sColumn,sRow,tColumn,tRow))
		{
			return 1;
		}
		return 0;
    }if(chessPiece == 'q' || chessPiece == 'Q')
    {
       	if(isQueenMovable(board,sColumn,sRow,tColumn,tRow))
		{
			return 1;
		}
		return 0;
    }
    if(chessPiece == 'p' || chessPiece == 'P')
    {
       	if(isPawnMovable(board,sColumn,sRow,tColumn,tRow))
		{
			return 1;
		}
		return 0;
    }
   
	return 0;
	
}
int isRookMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow)
{
	int sourcePoint,targetPoint,tempPoint;

	sourcePoint = coordinateFinder(sourceCol,sourceRow);
	targetPoint = coordinateFinder(targetCol,targetRow);

	tempPoint = sourcePoint;

	if(colorFinder(board,targetPoint,targetPoint) )
	{
		return 0;
	}
	else if( sourceCol == targetCol && sourceRow != targetRow)
	{
		if(tempPoint > targetPoint)
		{	
			do
			{
				tempPoint-=8;
				if(tempPoint > targetPoint && board[tempPoint] != ' ')
				{
					return 0;
				}
				else if(tempPoint == targetPoint)			
				{
					return 1;
				}
			}while(tempPoint >= targetPoint);
		}
		else if(tempPoint < targetPoint)
		{
			do
			{
				tempPoint+=8;
				if(tempPoint < targetPoint && board[tempPoint] != ' ')
				{
					return 0;
				}
				else if(tempPoint == targetPoint)			
				{
					return 1;
				}
			}while(tempPoint <= targetPoint);
		}
	}
	else if( sourceCol != targetCol && sourceRow == targetRow)
	{
		if(tempPoint > targetPoint)
		{	
			do
			{
				tempPoint-=1;
				if(tempPoint > targetPoint && board[tempPoint] != ' ')
				{
					return 0;
				}
				else if(tempPoint == targetPoint)			
				{
					return 1;
				}
			}while(tempPoint >= targetPoint);
		}
		else if(tempPoint < targetPoint)
		{
			do
			{
				tempPoint+=1;
				if(tempPoint < targetPoint && board[tempPoint] != ' ')
				{
					return 0;
				}
				else if(tempPoint == targetPoint)			
				{
					return 1;
				}
			}while(tempPoint <= targetPoint);
		}
	}
	
	return 0;
}
int isKnightMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow)
{
	int sourcePoint,targetPoint;
	int colDif,rowDif;

	sourcePoint = coordinateFinder(sourceCol,sourceRow);
	targetPoint = coordinateFinder(targetCol,targetRow);

	if(colorFinder(board,sourcePoint,targetPoint) && board[sourcePoint]!=' ')
	{
		return 0;
	}

	
	

	colDif = abs((int)(sourceCol - targetCol));
	rowDif = abs((int)(sourceRow - targetRow));

	if((colDif == 2 && rowDif == 1) || (colDif == 1 && rowDif == 2 ))
	{
		if(board[sourcePoint] == ' ' || (!colorFinder(board,sourcePoint,targetPoint)))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	return 0;
}
int isBishopMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow)
{
	int sourcePoint,targetPoint,tempPoint,difference,colDif,rowDif;

	sourcePoint = coordinateFinder(sourceCol,sourceRow);
	targetPoint = coordinateFinder(targetCol,targetRow);

	colDif = abs((int)(sourceCol - targetCol));
	rowDif = abs((int)(sourceRow - targetRow));

	if(colorFinder(board,sourcePoint,targetPoint) && board[sourcePoint]!=' ')
	{
		return 0;
	}

	tempPoint = sourcePoint;
	difference = abs(tempPoint - targetPoint);

	colDif = abs((int)(sourceCol - targetCol));
	rowDif = abs((int)(sourceRow - targetRow));

	if(colDif != rowDif)
	{
		return 0;
	}

	if((difference % 7 == 0) || (difference % 9) == 0)
	{
		if(tempPoint < targetPoint && tempPoint % 7 == 0)
		{
			do
			{
				tempPoint+=7;
				if((tempPoint < targetPoint) && (board[tempPoint] != ' '))
				{
					return 0;
				}
				else if(tempPoint == targetPoint)
				{
					return 1;
				}
			}while(tempPoint < targetPoint);
		}
		else if(tempPoint < targetPoint && tempPoint % 9 == 0)
		{
			do
			{
				tempPoint+=9;
				if((tempPoint < targetPoint) && (board[tempPoint] != ' '))
				{
					return 0;
				}
				else if(tempPoint == targetPoint)
				{
					return 1;
				}
			}while(tempPoint < targetPoint);
		}
		else if(tempPoint > targetPoint && tempPoint % 7 == 0)
		{
			
			do
			{
				tempPoint-=7;
				if((tempPoint < targetPoint) && (board[tempPoint] != ' '))
				{
					return 0;
				}
				else if(tempPoint == targetPoint)			
				{
					return 1;
				}
			}while(tempPoint > targetPoint);
		}
		else if(tempPoint > targetPoint && tempPoint % 9 == 0)
		{
			do
			{
				tempPoint-=9;
				if((tempPoint < targetPoint) && (board[tempPoint] != ' '))
				{
					return 0;
				}
				else if(tempPoint == targetPoint)
				{
					return 1;
				}
			}while(tempPoint < targetPoint);
		}
	}
		
	return 0;

}
int isKingMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow)
{
	int sourcePoint,targetPoint,tempPoint,difference;
	int colDif,rowDif;

	sourcePoint = coordinateFinder(sourceCol,sourceRow);
	targetPoint = coordinateFinder(targetCol,targetRow);

	colDif = abs((int)(sourceCol - targetCol));
	rowDif = abs((int)(sourceRow - targetRow));

	if(colorFinder(board,sourcePoint,targetPoint) )
	{
		return 0;
	}

	tempPoint = sourcePoint;
	difference = abs(tempPoint - targetPoint);
	
	if((difference == 7 ) || (difference == 9))
	{
		if(colDif == rowDif)
		{
			return 1;
		}
	}
	else if( difference == 8)
	{
		return 1;
	}
	else if(difference == 1 )
	{
		return 1;
	}

	return 0;
}
int isQueenMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow)
{
	/*int sourcePoint,targetPoint,tempPoint;*/
	/*int difference;*/

	/*sourcePoint = coordinateFinder(sourceCol,sourceRow);
	targetPoint = coordinateFinder(targetCol,targetRow);
	
	tempPoint = sourcePoint;*/
	/*difference = abs(tempPoint - targetPoint);*/

	return 0;

	/*if()*/

}
int isPawnMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow)
{
	int sourcePoint,targetPoint,tempPoint,difference;

	sourcePoint = coordinateFinder(sourceCol,sourceRow);
	targetPoint = coordinateFinder(targetCol,targetRow);
	tempPoint = sourcePoint;

	difference = abs(tempPoint - targetPoint);


	if( isupper(board[sourcePoint]) && tempPoint > targetPoint )/*White pawn*/
	{
		if( difference == 8 && board[targetPoint] == ' ')
		{
			return 1;
		}
		else if((difference == 7 || difference == 9) && islower(targetPoint))
		{
			return 1;
		}
		return 0;
	}
	else if(islower(board[sourcePoint]) && tempPoint < targetPoint)/*Black pawn*/
	{
		if( difference == 8 && board[targetPoint] == ' ')
		{
			return 1;
		}
		else if((difference == 7 || difference == 9) && isupper(targetPoint))
		{
			return 1;
		}
		
		return 0;
	}

	return 0;

	

}
int colorFinder(char *board,int sourcePoint,int targetPoint)
{
	int a=0,b=0;
	if((int)board[sourcePoint] >= 65 && (int)board[sourcePoint] <= 90)        
		a = 1;

	if((int)board[targetPoint] >= 65 && (int)board[targetPoint] <= 90) 
		b =1;

	if( a == b)
	{
		return 1;
	}
		return 0;
}

int coordinateFinder(char col,int row)
{

	int coordinate;/*For return value*/
	int intColumn;/*For Column's integer value*/

	intColumn = (int)tolower(col) - 96;

	coordinate = (abs(row - 8) * 8) + (intColumn - 1);

	return coordinate;
}
void initBoard(char *board)
{
    
  board[0]='r',board[1]='n',board[2]='b',board[3]='q',board[4]='k',board[5]='b',board[6]='n',board[7]='r',
  board[8]='p',board[9]='p',board[10]='p',board[11]='p',board[12]='p',board[13]='p',board[14]='p',board[15]='p',
  board[16]=' ',board[17]=' ',board[18]=' ',board[19]=' ',board[20]=' ',board[21]=' ',board[22]=' ',board[23]=' ',
  board[24]=' ',board[25]=' ',board[26]=' ',board[27]=' ',board[28]=' ',board[29]=' ',board[30]=' ',board[31]=' ',
  board[32]=' ',board[33]=' ',board[34]=' ',board[35]=' ',board[36]=' ',board[37]=' ',board[38]=' ',board[39]=' ',
  board[40]=' ',board[41]=' ',board[42]=' ',board[43]=' ',board[44]=' ',board[45]=' ',board[46]=' ',board[47]=' ',
  board[48]='P',board[49]='P',board[50]='P',board[51]='P',board[52]='P',board[53]='P',board[54]='P',board[55]='P',
  board[56]='R',board[57]='N',board[58]='B',board[59]='Q',board[60]='K',board[61]='B',board[62]='N',board[63]='R';

}
void printBoard(char *board)
{
	int i;
		printf("  a b c d e f g h\n");
	printf("  - - - - - - - -\n");
	printf("8|");
	for(i = 0; i <= 7;++i)
	{
		if(!(i==0 || i==8))
		{
			printf(" ");
		}
		printf("%c",board[i]);
	}
	printf("|\n7|");
	for (i = 8; i <= 15; ++i)
	{
		if(!(i==8 || i==16))
		{
			printf(" ");
		}
		printf("%c",board[i]);
	}
	printf("|\n6|");
	for (i = 16; i <= 23; ++i)
	{
		if(!(i==16 || i==24))
		{
			printf(" ");
		}
		printf("%c",board[i]);
	}
	printf("|\n5|");
	for (i = 24; i <= 31; ++i)
	{
		if(!(i==24 || i==32))
		{
			printf(" ");
		}
		printf("%c",board[i]);
	}
	printf("|\n4|");
	for (i = 32; i <= 39; ++i)
	{
		if(!(i==32 || i==40))
		{
			printf(" ");
		}
		printf("%c",board[i]);
	}
	printf("|\n3|");
	for (i = 40; i <= 47; ++i)
	{
		if(!(i==40 || i==48))
		{
			printf(" ");
		}
		printf("%c",board[i]);
	}
	printf("|\n2|");
	for (i = 48; i <= 55; ++i)
	{
		if(!(i==48 || i==56))
		{
			printf(" ");
		}
		printf("%c",board[i]);
	}
	printf("|\n1|");
	for (i = 56; i <= 63; ++i)
	{
		if(!(i==56 || i==64))
		{
			printf(" ");
		}
		printf("%c",board[i]);
	}
	printf("|\n  - - - - - - - -\n");
}

