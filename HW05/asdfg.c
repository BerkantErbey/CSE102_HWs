#include <stdio.h>
#include <string.h>
#include <ctype.h>


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
int sameColor(char *board,int sourcePoint,int targetPoint);
/*Hangi tas olduğunu bulsun,switch caselede o fonksiyonu is piece movable a dondursun*/



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
void getPosition(char *col,int *row)
{
	
	scanf("%c",col);

	scanf("%d",row);


}
int isValidCell(char col,int row)
{
	
	if( ( col >= 'a' || col <= 'h' ) && ( row >= '1' || row <= '8' ) )
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
	int sourceColumn,targetColumn;/*For colums num stored in this variable*/
	char chessPiec,spacchar;/**/


	getPosition(&sColumn,&sRow);
	isValidCell(&sColumn,&sRow);

	scanf("%c",&spaceChar);
	
	getPosition(&tColumn,&tRow);
	isValidCell(&tColumn,&tRow);

	/*Char to int conversion*/
	

	/*One dimensional array conversion*/
	if( 1 == isValidCell(&sColumn,&sRow))
	{
		switch (board[s])
		{
			case 'r':
			case 'R': isRookMovable(board,sColumn,sRow,tColumn,tRow); 
				break;
			case 'n': 
			case 'N': isKnightMovable(board,sColumn,sRow,tColumn,tRow); 					
				break;
			case 'b':
			case 'B': isBishopMovable(board,sColumn,sRow,tColumn,tRow); 					
				break;
			case 'k':
			case 'K': isKingMovable(board,sColumn,sRow,tColumn,tRow);						
				break;
			case 'q': 
			case 'Q': isQueenMovable(board,sColumn,sRow,tColumn,tRow);						
				break;
			case 'p': 
			case 'P': isPawnMovable(board,sColumn,sRow,tColumn,tRow);						
				break;
		}
	}
	

	

	/*Understand the white or black*/
	if( board[s] >= (char)97 && board[s] <= (char)114 )


}
int isRookMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow)
{
	int sourcePoint,targetPoint,tempPoint,difference;

	sourcePoint = coordinateFinder(sourceCol,sourceRow);
	targetPoint = coordinateFinder(targetCol,targetRow);

	if(sameColor(board,sourcePoint,targetPoint) && board[sourcePoint]!=' ')
	{
		return 0;
	}
	
	tempPoint = sourcePoint;
	difference = abs(tempPoint - targetPoint);

	if( difference % 8 == 0 )
	{
		if(tempPoint < targetPoint)
		{
			do
			{
				tempPoint += 8;
				if((tempPoint < targetPoint) && (board[tempPoint] != ' '))
				{
					return 0;
				}
				else if(tempPoint == targetPoint)
				{
					return 1;
				}
				
			}while(tempPoint <= targetPoint);
		}
		else
		{
			do
			{
				tempPoint -= 8;
				if((tempPoint > targetPoint) && (board[tempPoint] != ' '))
				{
						return 0;
				}
				else if(tempPoint == targetPoint)
				{
						return 1;
				}
				
			}while(tempPoint >= targetPoint);
		}
	}
	else if(difference <= 7)
	{
		if(tempPoint < targetPoint)
		{
			do
			{
				tempPoint+=1;
				if((tempPoint < targetPoint) && (board[tempPoint] != ' '))
				{
					return 0;
				}
				else if(tempPoint == targetPoint)
				{
						return 1;
				}
			}while(tempPoint <= targetPoint);
		}
		if(tempPoint > targetPoint)
		{
			do
			{
				tempPoint-=1;
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
	}
	return 0;
}
int isKnightMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow)
{
	int sourcePoint,targetPoint,tempPoint,difference;

	sourcePoint = coordinateFinder(sourceCol,sourceRow);
	targetPoint = coordinateFinder(targetCol,targetRow);

	if(sameColor(board,sourcePoint,targetPoint) && board[sourcePoint]!=' ')
	{
		return 0;
	}

	tempPoint = sourcePoint;
	difference = abs(tempPoint - targetPoint);

	if(difference == 15 ||difference == 17 || difference == 10)
	{
		return 1;
	}
	else if((difference == 6) && (tempPoint >= 8))
	{
		return 1;
	}

	return 0;
}
int isBishopMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow)
{
	int sourcePoint,targetPoint,tempPoint,difference;

	sourcePoint = coordinateFinder(sourceCol,sourceRow);
	targetPoint = coordinateFinder(targetCol,targetRow);

	if(sameColor(board,sourcePoint,targetPoint) && board[sourcePoint]!=' ')
	{
		return 0;
	}

	tempPoint = sourcePoint;
	difference = abs(tempPoint - targetPoint);

	if((difference % 7 == 0) || (difference % 9) == 0)
	{
		if(tempPoint < targetPoint )
		{
			if(tempPoint % 7 == 0 && sourcePoint >=8 && sourcePoint <=55 )
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
				}while(tempPoint <= targetPoint);
			}
			else if(tempPoint % 9 == 0)
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
				}while(tempPoint <= targetPoint);
			}
		else if(tempPoint > targetPoint)
		{
			if(tempPoint % 7 == 0)
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
				}while(tempPoint >= targetPoint);
			}
			else if(tempPoint % 9 == 0)
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
				}while(tempPoint <= targetPoint);
			}
		}
		
	}

	return 0;

}
int isKingMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow)
{
	int sourcePoint,targetPoint,tempPoint,difference;

	sourcePoint = coordinateFinder(sourceCol,sourceRow);
	targetPoint = coordinateFinder(targetCol,targetRow);

	if(sameColor(board,sourcePoint,targetPoint) && board[sourcePoint]!=' ')
	{
		return 0;
	}

	tempPoint = sourcePoint;
	difference = abs(tempPoint - targetPoint)
	
	if((difference >= 7 ) && (diffence <= 9))
	{
		return 1;
	}
	else if(difference < 2)
	{
		return 1;
	}

	/*return 0;*/
}
int isQueenMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow)
{
	int sourcePoint,targetPoint,tempPoint,difference;

	sourcePoint = coordinateFinder(sourceCol,sourceRow);
	targetPoint = coordinateFinder(targetCol,targetRow);
	
	tempPoint = sourcePoint;
	difference = abs(tempPoint - targetPoint);

	if()

}
int isPawnMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow)
{
	int sourcePoint,targetPoint,tempPoint,difference;

	sourcePoint = coordinateFinder(sourceCol,sourceRow);
	targetPoint = coordinateFinder(targetCol,targetRow);

	if(sameColor(board,sourcePoint,targetPoint) && board[sourcePoint] != ' ')
	{
		return 0;
	}

	tempPoint = sourcePoint;

	if( ! (tempPoint < targetPoint) )
	{
		return 0;
	}
	else
	{
		if( ((tempPoint + 8) == targetPoint) && board[targetPoint] == ' ')
		{
			return 1;
		}
		else if(!(sameColor(board,tempPoint,targetPoint)) )
		{
			if( ((tempPoint + 7) == targetPoint) || ((tempPoint + 9) == targetPoint))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}

}
int sameColor(char *board,int sourcePoint,int targetPoint)
{

	int s,t;

	s = islower(board[sourcePoint]);
	t = islower(board[targetPoint]);

	if( s == t)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int coordinateFinder(char col,int row)
{

	int coordinate;/*For return value*/
	int intColumn;/*For Column's integer value*/


	intColumn = (int)col - 96;

	coordinate = ((row - 1) * 8) + (intColumn - 1);

	return coordinate;
}
void initBoard(char board[]){
  
  int i;
  
  board[0]='R';
  board[1]='N';
  board[2]='B';
  board[3]='Q';
  board[4]='K';
  board[5]='B';
  board[6]='N';
  board[7]='R';
  
  for(i=8; i<=55; i++ ){
    
    if(i<=15){
      board[i]='P';  
    }else{
    
      if(i>47){
        board[i]='p';  
      }else{
        board[i]=' ';
      }
    }
  }
  board[56]='r';
  board[57]='n';
  board[58]='b';
  board[59]='q';
  board[60]='k';
  board[61]='b';
  board[62]='n';
  board[63]='r';
  
}
