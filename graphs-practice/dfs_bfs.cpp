#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

#define N 10

using namespace std;

vector<int> adj[N];
vector<bool> visited(N, false);

void dfs(int v){
	if(visited[v]){
		return;
	}
	cout << v << " ";
	visited[v] = true;
	for (int i = 0; i < adj[v].size(); ++i){
		int u = adj[v][i];
		dfs(u);
	}
	return;
}

void bfs(int start){
	queue<int> q;
	q.push(start);
	cout << start << " ";
	visited[start] = true;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for (int i = 0; i < adj[u].size(); ++i){
			int v = adj[u][i];
			if(!visited[v]){
				q.push(v);
				visited[v] = true;
				cout << v << " ";
			}
		}
	}
}

int main(){
	adj[0].push_back(1);
	adj[0].push_back(2);
	adj[0].push_back(3);
	adj[1].push_back(0);
	adj[1].push_back(4);
	adj[1].push_back(5);
	adj[2].push_back(0);
	adj[2].push_back(6);
	adj[3].push_back(0);
	adj[3].push_back(7);
	adj[3].push_back(8);
	dfs(0);
	cout << endl;
	//Reinitialize the visited vector to false
	for (int i = 0; i < N; ++i)
		visited[i] = false;
	bfs(0);
	cout << endl;
	return 0;
}