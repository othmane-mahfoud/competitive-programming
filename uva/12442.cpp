#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

const int N = 1234567;
int c = 0;
vector<int> adj[N];
int vis[N];

void dfs(int u) {
	vis[u] = 1;
	c++;
	for (auto v: adj[u]) {
		if (!vis[v]) {
			dfs(v);
		}
	}
}

int main() {
	int t;
	int n;
	cin >> t;
	for (int i = 0; i < t; ++i){
		cin >> n;
		for (int a = 0; a <= n; a++) adj[a].clear();
		for (int j = 0; j < n; ++j){
			int u,v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		int max = 0;
		int hadak;
		for (int k = 1; k <= n; ++k){
			c = 0;
			memset(vis, 0, sizeof vis);
			dfs(k);
			if (c > max){
				max = c;
				hadak = k;
			}
		}
		cout << "Case " << i+1 << ": " << hadak << endl;
	}
	return 0;
}