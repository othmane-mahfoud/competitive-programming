#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

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

void dijkstra(int start){
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push(make_pair(dist[start], start));
	while(!pq.empty()){
		int u = pq.top().second,
			d = pq.top().first;
		pq.pop();
		if(d > dist[u]) continue;
		for (int i = 0; i < adj[u].size(); ++i){
			int v = adj[u][i].v;
			int w = adj[u][i].weight;
			if(w + dist[u] < dist[v]){
				dist[v] = w + dist[u];
				pq.push(make_pair(dist[v], v));
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
	dijkstra(0);
	cout << dist[3] << endl;
}