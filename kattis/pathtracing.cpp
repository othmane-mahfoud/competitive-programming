#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int main (){
	
	int sizeLeftRight = 0, sizeBottomUp = 0, minLR = 0, maxLR = 0, minBU = 0, maxBU = 0;
	int startCol, startRow, endCol, endRow;
	queue<string> moves;
	string move;
	
	while(cin >> move){
		if (move.compare("up") == 0){
			sizeBottomUp++;
			if (sizeBottomUp > maxBU)
			{
				maxBU = sizeBottomUp;
			}
		}
		else if(move.compare("down") == 0){
			sizeBottomUp--;
			if (sizeBottomUp < minBU)
			{
				minBU = sizeBottomUp;
			}
		}
		else if(move.compare("left") == 0){
			sizeLeftRight--;
			if (sizeLeftRight < minLR)
			{
				minLR = sizeLeftRight;
			}
		}
		else if(move.compare("right") == 0){
			sizeLeftRight++;
			if (sizeLeftRight > maxLR)
			{
				maxLR = sizeLeftRight;
			}
		}
		moves.push(move);
	}
	
	sizeLeftRight = maxLR - minLR + 1;
	sizeBottomUp = maxBU - minBU + 1;
	startCol = abs(minLR) + 1;
	startRow = maxBU + 1;
	endRow = startRow + maxBU + minBU;
	endCol = startCol + maxLR + minLR;

	char myMap[sizeBottomUp + 2][sizeLeftRight + 2];
	int markCol = startCol, markRow = startRow;

	for (int i = 0; i < sizeBottomUp + 2; ++i)
	{
		for (int j = 0; j < sizeLeftRight + 2; ++j)
		{
			myMap[i][j] = ' ';
		}
	}
	
	while(!moves.empty()){
		if (moves.front().compare("up")==0)
		{
			myMap[--markRow][markCol] = '*';
			moves.pop();
		}
		else if (moves.front().compare("down")==0)
		{
			myMap[++markRow][markCol] = '*';
			moves.pop();
		}
		else if (moves.front().compare("left")==0)
		{
			myMap[markRow][--markCol] = '*';
			moves.pop();
		}
		else if (moves.front().compare("right")==0)
		{
			myMap[markRow][++markCol] = '*';
			moves.pop();
		}
	}
	
	myMap[startRow][startCol] = 'S';
	myMap[endRow][endCol] = 'E';

	for (int i = 0; i < sizeBottomUp + 2; ++i)
	{
		for (int j = 0; j < sizeLeftRight + 2; ++j)
		{
			if(i==0 || i==sizeBottomUp+1 || j==0 || j==sizeLeftRight+1){
				printf("#");
			}
			else{
				cout << myMap[i][j];
			}
		}
		printf("\n");
	}

	return 0;
}