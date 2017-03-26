#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


void emptyBuffer();

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

int colorFinder(char *board,int point);
/*Space->0------White->1------Black->2*/

/*typedef enum
{
	R,r,N,n,B,b,Q,q,K,k,P,p
}	piecetype;
*/

int main()
{

	char board [64];
	int initComplete = 0;
	char empty;

	int command;
	scanf("%d", &command);

	while(command!=4)
	{
		switch(command)
		{
			case 1: initBoard(board); 
				initComplete = 1; 
				printf("OK\n");
				break;
			case 2: 
				/*Read space character after command number*/
				scanf("%c", &empty);
				if (initComplete)
				{
					if(isPieceMovable(board))
						printf("YES\n");
					else
						printf("NO\n");
				}
				else
				{  
					printf("Board is not initialized!\n");
					emptyBuffer();
				}
				break;
			case 3: 
				if (initComplete)
					printBoard(board);
				else  
					printf("Board is not initialized!\n");
					emptyBuffer();
				break;

			default: printf("Invalid command!\n"); emptyBuffer(); break;

		}	
		
		scanf("%d", &command);
	
	}
	return 0;

}
void emptyBuffer()
{
	while ( getchar() != '\n' );
}


void getPosition(char *col,int *row)
{
	
	char empty;
	
	scanf("%c%d",col,row);
	scanf("%c",&empty);

}
int isValidCell(char col,int row)
{	
	
	col = tolower(col);

	if( ( col >= 'a' && col <= 'h' ) && ( row >= 1 && row <= 8 ) )
	{
		return 1;
	}	
	
	return 0;
}

int isPieceMovable(char *board)
{
	char sColumn,tColumn;/*For store the C*/
	int sRow,tRow;
	
	char chessPiece;
	
	int ret=0;
	int s;
	printf("1->Tamam\t");
	getPosition(&sColumn,&sRow);
	getPosition(&tColumn,&tRow);
	
	printf("2->Tamam\t");
	if(isValidCell(sColumn,sRow) == 0  || isValidCell(tColumn,tRow) == 0)
	{
		ret = 0;
		printf("3->>\t");
	}
	
	s = coordinateFinder(sColumn,sRow);	/*Inıtialization to source point*/
	

	if(board[s] == ' ')
	{
		printf("6--\t");
		ret = 0;
	}
	
	
	chessPiece = board[s];
    
    printf("%c\t",chessPiece);
    
    switch(chessPiece)
    {
    	case 'r':
    	case 'R':
    		ret= isRookMovable(board,sColumn,sRow,tColumn,tRow);
    	case 'n':
    	case 'N':
    		ret= isKnightMovable(board,sColumn,sRow,tColumn,tRow);
    	case 'b':
    	case 'B':
    		ret= isBishopMovable(board,sColumn,sRow,tColumn,tRow);
    	case 'q':
    	case 'Q':
    		ret= isQueenMovable(board,sColumn,sRow,tColumn,tRow);
    	case 'k':
    	case 'K':
    		ret = isKingMovable(board,sColumn,sRow,tColumn,tRow);
    	case 'p':
    	case 'P':
    		ret = isPawnMovable(board,sColumn,sRow,tColumn,tRow);
	}

    printf("8--\n");
    
    
	return ret;
	
}
int isRookMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow)
{
/*	int sourcePoint,targetPoint,tempPoint;

	sourcePoint = coordinateFinder(sourceCol,sourceRow);
	targetPoint = coordinateFinder(targetCol,targetRow);

	tempPoint = sourcePoint;

	if(colorFinder(board,point) == colorFinder )
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
*/
	return 0;
}
int isKnightMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow)
{
/*	int sourcePoint,targetPoint;
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
*/
	return 0;
}
int isBishopMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow)
{
	int sourcePoint,targetPoint,difference,colDif,rowDif;

	sourcePoint = coordinateFinder(sourceCol,sourceRow);
	targetPoint = coordinateFinder(targetCol,targetRow);

	colDif = abs((int)(sourceCol - targetCol));
	rowDif = abs(sourceRow - targetRow);

	tempPoint = sourcePoint;
	difference = abs(tempPoint - targetPoint);

	if(colDif != rowDif)
	{
		return 0;
	}
	else
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
/*	int sourcePoint,targetPoint,tempPoint,difference;
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
*/
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
	int sourcePoint,targetPoint;/*For source and target coordinate 1D array*/
	int colorS,colorT;					/*For piece's color*/
	int difference;				/*Difference between the source and target point*/
	int ans = 0;					/*Return Value*/
	
	sourcePoint = coordinateFinder(sourceCol,sourceRow);
	targetPoint = coordinateFinder(targetCol,targetRow);
	
	printf("S->%d\tT->%d",sourcePoint,targetPoint);
	
	difference = abs(sourcePoint - targetPoint);

	
	
	colorS =colorFinder(board,sourcePoint);
	colorT = colorFinder(board,targetPoint);


	if( colorS == 1 && sourcePoint > targetPoint )/*White pawn*/
	{
		if( difference == 8 && board[targetPoint] == ' ')
		{
			ans = 1;
		}
		else if((difference == 7 || difference == 9) && colorT == 2)
		{
			ans = 1;
			
		}
	
	}
	else if(colorS == 2 && sourcePoint < targetPoint)/*Black pawn*/
	{
		if( difference == 8 && board[targetPoint] == ' ')
		{
			ans = 1;
		}
		else if((difference == 7 || difference == 9) && colorT == 1)
		{
			ans = 1;
		}
	}

	return ans;

}
int colorFinder(char *board,int point)
{
	int ret;			/*Return Value*/ 
	
	ret = 0; 			/*Base case for Space*/
	

	/*White Piece*/
	if(board[point] >= 'B' && board[point] <= 'R')        
	{	

		ret = 1;
	}

	/*Black Piece*/
	if(board[point] >= 'b' && board[point] <= 'r') 
	{

		ret = 2;
	}

	return ret;

}
int coordinateFinder(char col,int row)
{

	int coordinate;		/*For return value*/
	int intColumn;		/*For Column's integer value*/

	intColumn = (int)tolower(col)-96;



	coordinate = (abs(row - 8) * 8) + (intColumn-1);
	/*printf("Coordinate->%d\n",coordinate );*/
	return coordinate;
}
void initBoard(char *board)
{
    
  board[0]=' ',board[1]=' ',board[2]=' ',board[3]=' ',board[4]=' ',board[5]=' ',board[6]=' ',board[7]=' ',
  board[8]=' ',board[9]=' ',board[10]=' ',board[11]=' ',board[12]=' ',board[13]=' ',board[14]=' ',board[15]=' ',
  board[16]=' ',board[17]=' ',board[18]=' ',board[19]=' ',board[20]=' ',board[21]=' ',board[22]=' ',board[23]=' ',
  board[24]=' ',board[25]=' ',board[26]=' ',board[27]=' ',board[28]=' ',board[29]=' ',board[30]=' ',board[31]=' ',
  board[32]=' ',board[33]=' ',board[34]='p',board[35]=' ',board[36]=' ',board[37]=' ',board[38]=' ',board[39]=' ',
  board[40]='p',board[41]=' ',board[42]='P',board[43]='p',board[44]=' ',board[45]=' ',board[46]=' ',board[47]=' ',
  board[48]=' ',board[49]='P',board[50]=' ',board[51]=' ',board[52]=' ',board[53]=' ',board[54]=' ',board[55]=' ',
  board[56]=' ',board[57]=' ',board[58]=' ',board[59]=' ',board[60]=' ',board[61]=' ',board[62]=' ',board[63]=' ';

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