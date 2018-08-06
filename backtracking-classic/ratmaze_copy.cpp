#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void printSolution(int sol[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}

bool isSafe(int maze[4][4], int x, int y)
{
    // if (x,y outside maze) return false
    if(x >= 0 && x < 4 && y >= 0 && y < 4 && maze[x][y] == 1)
        return true;
 
    return false;
}

bool escape(int maze[4][4], int row, int col, int sol[4][4]){
	if (row==3 && col==3){
		sol[row][col] = 1;
		return true;
	}
	if (isSafe(maze, row, col) == true){
		sol[row][col] = 1;
		if(escape(maze, row + 1, col, sol)){
			return true;
		}
		if(escape(maze, row, col + 1, sol)){
			return true;
		}
		sol[row][col] = 0;
		return false;
	}
	return false;
}

bool solveMaze(int maze[4][4])
{
    int sol[4][4] = { {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
 
    if(escape(maze, 0, 0, sol) == false)
    {
        printf("Solution doesn't exist");
        return false;
    }
 
    printSolution(sol);
    return true;
}

int main(){
	int maze[4][4];
	int sol[4][4];
	memset(maze, 0, sizeof(maze));
	maze[0][0] = 1;
	maze[1][0] = 1;
	maze[1][1] = 1;
	maze[1][3] = 1;
	maze[2][1] = 1;
	maze[3][0] = 1;
	maze[3][1] = 1;
	maze[3][2] = 1;
	maze[3][3] = 1;
	solveMaze(maze);
}