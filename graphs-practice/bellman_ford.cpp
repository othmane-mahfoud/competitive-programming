#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define N 4

using namespace std;

struct edge{
	int u, v;
	int weight;
	edge(int _u, int _v, int _w){
		u = _u;
		v = _v;
		weight = _w;
	}
};

vector<edge> adj[100];
vector<int> dist(100, INT_MAX);

void bellman_ford(int start){
	dist[start] = 0;
	for (int i = 0; i < N-1; ++i){
		for (int u = 0; u < N; ++u){
			for (int j = 0; j < adj[u].size(); ++j){
				int v = adj[u][j].v;
				int w = adj[u][j].weight;
				dist[v] = min(dist[v], w + dist[u]);
			}
		}
	}
}

void init(){
	adj[0].push_back(edge(0, 1, 3));
	adj[0].push_back(edge(0, 2, 4));
	adj[1].push_back(edge(1, 0, 3));
	adj[1].push_back(edge(1, 2, 0));
	adj[2].push_back(edge(2, 0, 4));
	adj[2].push_back(edge(2, 1, 0));
	adj[2].push_back(edge(2, 3, 2));
	adj[3].push_back(edge(3, 2, 2));
}

int main(){
	init();
	bellman_ford(0);
	cout << dist[3] << endl;
	bellman_ford(0);
	cout << dist[3] << endl;
}