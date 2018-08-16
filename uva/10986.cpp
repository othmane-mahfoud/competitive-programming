#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

#define INF 1000000000 

using namespace std;

struct edge{
	long long u, v, w;
	edge(long long _u, long long _v, long long _w){
		u = _u;
		v = _v;
		w = _w;
	}
};

vector<edge> adj[100000];
vector<long long> dist(100000, INF);

void dijkstra(long long start){
	dist[start] = 0;
	priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, greater<pair<long long, long long> > > pq;
	pq.push(make_pair(dist[start], start));
	while(!pq.empty()){
		long long u = pq.top().second,
			d = pq.top().first;
		pq.pop();
		if(d > dist[u]) continue;
		for (long long i = 0; i < adj[u].size(); ++i){
			long long v = adj[u][i].v;
			long long w = adj[u][i].w;
			if(w + dist[u] < dist[v]){
				dist[v] = w + dist[u];
				pq.push(make_pair(dist[v], v));
			}
		}
	}
}
int main(){
	long long x;
	cin >> x;
	for (long long i = 0; i < x; ++i){
		long long n, m, s, t;
		cin >> n >> m >> s >> t;
		for (long long j = 0; j < m; ++j){
			long long u, v, w;
			cin >> u >> v >> w;
			adj[u].push_back(edge(u,v,w));
			adj[v].push_back(edge(v,u,w));
		}
		dijkstra(s);
		if (dist[t]!=INF){
			cout << "Case #" << i + 1 << ": " << dist[t] << endl;
		}
		else{
			cout << "Case #" << i + 1 << ": unreachable" << endl;
		}
		for (long long j = 0; j < n; ++j){
			dist[j] = INF;
			adj[j].clear();
		}
	}
	return 0;
}