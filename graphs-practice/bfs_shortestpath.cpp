#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

#define N 6

using namespace std;

int visited[N];
vector<int> adj[N];
int sp[N];

void init(){
	adj[0].push_back(1);
	adj[0].push_back(2);
	adj[1].push_back(0);
	adj[1].push_back(3);
	adj[2].push_back(3);
	adj[2].push_back(4);
	adj[3].push_back(1);
	adj[3].push_back(2);
	adj[3].push_back(4);
	adj[3].push_back(5);
	adj[4].push_back(2);
	adj[4].push_back(3);
	adj[4].push_back(5);
	adj[5].push_back(3);
	adj[5].push_back(4);
}

void bfs(int start){
	queue<int> q;
	q.push(start);
	visited[start] = 1;
	sp[start] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for (int i = 0; i < adj[u].size(); ++i){
			int v = adj[u][i];
			if(!visited[v]){
				q.push(v);
				visited[v] = 1;
				sp[v] = min(sp[v], sp[u] + 1);
			}
		}
	}
}


int main(){

	init();
	memset(visited, 0, sizeof(visited));
	memset(sp, 12345, sizeof(sp));
	bfs(0);
	cout << sp[5] << endl;

}
