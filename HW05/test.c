#include <stdio.h>
#include <ctype.h>

int main()
{
	char c1='a',c2='b',c3=' ' ,c4 ='d',c5='e' ,c6='f' ,c7='g',c8='h';
	int r1=1,r2=2,r3=3,r4=4,r5=5,r6=6,r7=7,r8=8;

	int coordinate;
	int col;

	printf("a->%d/tA->%d/t' '->%d/t",islower(c1),islower(c2),islower(c3));



	/*coordinate=abs(r1-8)*8+()*/


	return 0;
}


int isRookMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow)
{
	int sourcePoint,targetPoint,tempPoint,difference;

	sourcePoint = coordinateFinder(sourceCol,sourceRow);
	targetPoint = coordinateFinder(targetCol,targetRow);

	tempPoint = sourcePoint;
	difference = abs(tempPoint - targetPoint);

	if(sameColor(board,sourcePoint,targetPoint) && board[sourcePoint]!=' ')
	{
		return 0;
	}
	else if( sourceCol == targetCol && sourceRow != targetRow)
	{
		if(tempPoint > sourcePoint)
		{	
			do
			{
				tempPoint-=8;
				if(tempPoint > sourcePoint && board[tempPoint] != ' ')
				{
					return 0;
				}
			}while(tempPoint > sourcePoint);
			return 1;;
		}
		else if(tempPoint < sourcePoint)
		{
			do
			{
				tempPoint+=8;
				if(tempPoint < sourcePoint && board[tempPoint] != ' ')
				{
					return 0;
				}
			}while(tempPoint < sourcePoint);
			return 1;
		}
	}
	else if( sourceCol != targetCol && sourceRow != targetRow)
	{
		if(tempPoint > sourcePoint)
		{	
			do
			{
				tempPoint-=1;
				if(tempPoint > sourcePoint && board[tempPoint] != ' ')
				{
					return 0;
				}
			}while(tempPoint > sourcePoint);
			return 1;;
		}
		else if(tempPoint < sourcePoint)
		{
			do
			{
				tempPoint+=1;
				if(tempPoint < sourcePoint && board[tempPoint] != ' ')
				{
					return 0;
				}
			}while(tempPoint < sourcePoint);
			return 1;
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

	if(sameColor(board,sourcePoint,targetPoint) && board[sourcePoint]!=' ')
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
	
	while( )




}
int coordinateFinder(char col,int row)
{

	int coordinate;/*For return value*/
	int intColumn;/*For Column's integer value*/

	intColumn = (int)col - 96;

	coordinate = ((row - 8) * 8) + (intColumn - 1);

	return coordinate;
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

	colDif = abs((int)(sourceCol - targetCol));
	rowDif = abs((int)(sourceRow - targetRow));

	if((coldif == 2 && rowDif == 1) || (coldif == 1 && rowDif == 2 )
	{
		if(board[sourcePoint] == ' ' || colorFinder(board,sourcePoint,targetPoint))
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