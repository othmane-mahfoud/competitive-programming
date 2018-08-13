#include <iostream>
#include <vector>

#define N 4

using namespace std;

struct union_find {
	vector<int> parent;
	vector<int> size;

	union_find(int n){
		parent = vector<int>(n);
		size = vector<int>(n);
		for (int i = 0; i < n; ++i){
			parent[i] = i;
			size[i] = 1;
		}
	}

	int find(int x) {
		if (parent[x] == x){
			return x;
		}
		else{
			parent[x] = find(parent[x]);
			return parent[x];
		}
	}

	void unite(int x, int y) {
		parent[find(x)] = find(y);
		size[parent[find(x)]] += size[find(y)];
	}

	int count(int x){
		return size[find(x)];
	}

};

struct edge {
	int u, v;
	int weight;
	edge(int _u, int _v, int _w){
		u      = _u;
		v      = _v;
		weight = _w;
	}
};

vector<edge> edges;
vector<bool> visited(1000, false);

bool edge_cmp(const edge &a, const edge &b){
	return a.weight < b.weight;
}

void init(){
	edges.push_back(edge(0, 1, 3));
	edges.push_back(edge(0, 2, -4));
	edges.push_back(edge(1, 2, 0));
	edges.push_back(edge(2, 3, 2));
}

vector<edge> kruskal(){
	union_find uf(N);
	sort(edges.begin(), edges.end(), edge_cmp);
	vector<edge> res;
	for (int i = 0; i < edges.size(); ++i){
		int u = edges[i].u, 
			v = edges[i].v;
		if (uf.find(u) != uf.find(v)){
			res.push_back(edges[i]);
			uf.unite(u, v);
		}
	}
	return res;
}

int main() {
	vector<edge> res;
	init();
	res = kruskal();
	for (int i = 0; i < res.size(); ++i){
		cout << res[i].u << "-" << res[i].v << endl;
	}
	return 0;
}