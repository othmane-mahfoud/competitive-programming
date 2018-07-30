#include <iostream>
#include <vector>
#include <algorithm>

#define n 4

using namespace std;

void printSolution(){

}

bool isSafe(int board[n][n], int row, int col){
	
}

bool placeQueensUtil(int board[n][n], int col){
	if(col >= n){
		return true;
	}
	else{
		for (int i = 0; i < n; ++i){
			if (isSafe(board, i, col)==true){
				board[i][col] = 1;
				if(placeQueensUtil(board, col+1)){
					return true;
				}
				board[i][col] = 0;
			}
		}
		return false;
	}
}

void placeQueens(int board[n][n]){
	if (placeQueensUtil(board, 0, 0, n)==true){
		printSolution(board[n][n]);
	}
	else{
		cout << "Sorry there is no solution in this case" << endl;
	}
}

int main(){
	int board[n][n];
	memset(board, 0, sizeof(board));
	placeQueens(board)
	return 0;
}