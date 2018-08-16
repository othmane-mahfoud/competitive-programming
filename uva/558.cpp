#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 1000000

using namespace std;

struct edge{
	int u, v, w;
	edge(int _u, int _v, int _w){
		u = _u;
		v = _v;
		w = _w;
	}
};

vector<edge> adj[2001];
vector<int> dist(2001, INF);

bool negCycleCheck(int start, int n){
	for (int i = 0; i < n; ++i)
	{
		dist[i] = INF;
	}
	dist[start] = 0;
	for (int i = 0; i < n-1; ++i)
	{
		for (int u = 0; u < n; ++u)
		{
			for (int j = 0; j < adj[u].size(); ++j)
			{
				int v = adj[u][j].v;
				int w = adj[u][j].w;
				dist[v] = min(dist[v], w + dist[u]);
			}
		}
	}

	for (int u = 0; u < n; ++u)
	{
		for (int j = 0; j < adj[u].size(); ++j)
		{
			int v = adj[u][j].v;
			int w = adj[u][j].w;
			if (dist[u] != INF && dist[u] + w < dist[v])
			{
				return true;
			}
		}
	}

	return false;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; ++i)
		{
			int u, v, w;
			cin >> u >> v >> w;
			adj[u].push_back(edge(u, v, w));
		}
		if(negCycleCheck(0, n))
			cout << "possible" << endl;
		else
			cout << "not possible" << endl;
		for (int i = 0; i < n; ++i)
		{
			adj[i].clear();
		}
	}
}