#include <iostream>
#include <vector>
#include <algorithm>

#define n 4

using namespace std;

void printSolution(){

}

bool isSafe(int board[n][n], int row, int col){
	 int i, j;
 
    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
 
    /* Check upper diagonal on left side */
    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return false;
 
    /* Check lower diagonal on left side */
    for (i=row, j=col; j>=0 && i<N; i++, j--)
        if (board[i][j])
            return false;
 
    return true;
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