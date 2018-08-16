#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<vector<long long> > adj;
long long visited[1000001];
long long dist[1000001];

void bfs(long long start){
	queue<long long> q;
	q.push(start);
	visited[start] = 1;
	dist[start] = 0;
	while(!q.empty()){
		long long u = q.front();
		q.pop();
		for (long long i = 0; i < adj[u].size(); ++i){
			long long v = adj[u][i];
			if(!visited[v]){
				q.push(v);
				visited[v] = 1;
				dist[v] = min(dist[v], dist[u]+1);
			}
		}
	}
}

int main(){
	long long r, c;
	while(true){
		cin >> r >> c;
		if(r==0 || c==0)
			break;
		adj.resize(r*c);
		for (long long i = 0; i < r*c ; ++i)
		{
			adj[i].resize(r*c);
		}
		long long grid[r][c];
		long long a = 0;
		for (long long i = 0; i < r; ++i)
		{
			for (long long j = 0; j < c; ++j)
			{
				grid[i][j] = a;
				a++;
			}
		}
		long long rows;
		cin >> rows;
		for (long long i = 0; i < rows; ++i){
			long long row;
			long long mines;
			cin >> row >> mines;
			for (long long j = 0; j < mines; ++j){
				long long col;
				cin >> col;
				grid[row][col] = -1;
			}
		}
		
		long long startRow, startCol, endRow, endCol;
		cin >> startRow >> startCol >> endRow >> endCol;
		for (long long i = 0; i < r; ++i){
			for (long long j = 0; j < c; ++j){
				if (i!=0)
				{
					if (grid[i-1][j]!=-1)
					{
						adj[grid[i][j]].push_back(grid[i-1][j]);
					}
				}
				if (j!=0)
				{
					if (grid[i][j-1]!=-1)
					{
						adj[grid[i][j]].push_back(grid[i][j-1]);
					}				
				}
				if (i!=r-1)
				{
					if (grid[i+1][j]!=-1)
					{
						adj[grid[i][j]].push_back(grid[i+1][j]);
					}
				}
				if (j!=c-1)
				{
					if (grid[i][j+1]!=-1)
					{
						adj[grid[i][j]].push_back(grid[i][j+1]);
					}
				}
			}
		}
		
		for (long long i = 0; i < r*c; ++i)
		{
			visited[i] = 0;
		}
		
		for (long long i = 0; i < r*c; ++i)
		{
			dist[i] = 10000;
		}
		bfs(grid[startRow][startCol]);
		cout << dist[grid[endRow][endCol]] << endl;
		for (long long i = 0; i < r*c; ++i){
			adj[i].clear();
		}
	}
	return 0;
}