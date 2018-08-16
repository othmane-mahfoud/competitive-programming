#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <map>

#define INF 1000000

typedef long long ll;

using namespace std;

int dist[100][100];
int weight[100][100];
int visited[101];

long long maxx (long long a, long long b){
	return a > b ? a : b;
}

void floyd_warshall(int n){
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			dist[i][j] = i == j ? 0 : weight[i][j];
		}
	}

	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

int main (){
	int t = 0;
	while(true){
		int u, v;
		cin >> u >> v;
		if (u == 0 && v == 0)
		{
			break;
		}
		t++;
		map<int, int> m;
		int n = 0;
		int maxVal = 0;
		for (int i = 0; i < 100; ++i)
		{
			for (int j = 0; j < 100; ++j)
			{
				weight[i][j] = 1000;
			}
		}
		for (int i = 0; i < 100; ++i)
		{
			for (int j = 0; j < 100; ++j)
			{
				dist[i][j] = 0;
			}
		}
		for (int j = 0; j < 101; ++j)
		{
			visited[j] = 0;
		}
		while(true){
			if (!visited[u]){
				visited[u] = 1;
				m[u] = n;
				n++;
			}
			if (!visited[v]){
				visited[v] = 1;
				m[v] = n;
				n++;
			}
			weight[m[u]][m[v]] = 1;
			cin >> u >> v;
			if (u == 0 && v == 0)
			{
				break;
			}
		}
		floyd_warshall(n);
		int total = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (dist[i][j]!=1000)
				{
					total += dist[i][j];
				}
			}
		}
		double result = (double)total / (double)(n*(n-1));
		printf("Case %d: average length between pages = %.3lf clicks\n", t, result);
		m.clear();
	}
	return 0;
}
