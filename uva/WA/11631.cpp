#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define N 200001

using namespace std;

struct union_find{
	vector<long long> parent;

	union_find(long long n){
		parent = vector<long long>(n);
		for (int i = 0; i < n; ++i){
			parent[i] = i;
		}
	}

	long long find(long long x){
		if (parent[x] == x)
			return parent[x];
		else {
			parent[x] = find(parent[x]);
			return parent[x];
		}
	}

	void unite(long long x, long long y){
		parent[find(x)] = find(y);
	}

};

struct edge {
	long long u, v;
	long long weight;
	edge(long long _u, long long _v, long long _w){
		u      = _u;
		v      = _v;
		weight = _w;
	}
};

vector<edge> edges;
vector<bool> visited(N, false);

bool edge_cmp(const edge &a, const edge &b){
	return a.weight < b.weight;
}

int kruskal(){
	union_find uf(N);
	sort(edges.begin(), edges.end(), edge_cmp);
	int res;
	for (long long i = 0; i < edges.size(); ++i){
		long long u = edges[i].u, 
			v = edges[i].v;
		if (uf.find(u) != uf.find(v)){
			res += edges[i].weight;
			uf.unite(u, v);
		}
	}
	return res;
}

int main(){
	freopen("o.txt", "w", stdout);
	long long m, n;
	while(true){
		cin >> m >> n;
		edges.clear();
		if(m == 0 && n == 0){
			break;
		}
		long long x, y, z;
		long long cost = 0;
		for (long long i = 0; i < n; ++i){
			cin >> x >> y >> z;
			cost += z;
			edges.push_back(edge(x, y, z));
		}
		long long res = kruskal();
		cout << cost - res << endl;
	}
}
