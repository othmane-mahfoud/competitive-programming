#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define INF 1000000

using namespace std;

int dist[100][100];

void floyd_warshall(int n, int weight[][4]){
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			dist[i][j] = weight[i][j];
		}
	}

	for (int k = 0; k < n; ++k){
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

int main(){
	int weight[4][4];
	weight[0][0] = 0;
	weight[1][1] = 0;
	weight[2][2] = 0;
	weight[3][3] = 0;
	weight[0][1] = 3;
	weight[0][2] = 4;
	weight[0][3] = INF;
	weight[1][0] = 3;
	weight[1][2] = 0;
	weight[1][3] = INF;
	weight[2][0] = 4;
	weight[2][1] = 0;
	weight[2][3] = 2;
	weight[3][0] = INF;
	weight[3][1] = INF;
	weight[3][2] = 2;
	floyd_warshall(4, weight);
	cout << dist[0][3] << endl;
	return 0;
}