#include <iostream>
#include <vector>
#include <cmath>

#define MAX_WEIGHT 13
#define ITEMS 4

using namespace std;

int maxVal(int dp[ITEMS+1][MAX_WEIGHT+1]){
	return dp[ITEMS][MAX_WEIGHT];
}

void takenItems(int dp[ITEMS+1][MAX_WEIGHT+1], int v[ITEMS], int w[ITEMS]){
	int i = ITEMS;
	int m = MAX_WEIGHT;
	while(true){
		if (dp[i][m] == dp[i-1][m])
			break;
		else{
			cout << i << " ";
			m = m - w[i-1];
			i--;
		}
	}
	cout << endl;
}

void knapsack (int dp[ITEMS+1][MAX_WEIGHT+1], int v[ITEMS], int w[ITEMS]){
	for (int i = 0; i <= ITEMS; ++i){
		for (int m = 0; m <= MAX_WEIGHT; ++m){
			if (i == 0 || m == 0)
				dp[i][m] = 0;
			else if (m < w[i-1])
				dp[i][m] = dp[i-1][m];
			else
				dp[i][m] = max(v[i-1] + dp[i-1][m-w[i-1]], dp[i-1][m]);
		}
	}
	cout << "The maximum value you can fit into the bag is: " << maxVal(dp) << endl;
	cout << "The items you can take are: ";
	takenItems(dp, v, w);
}

int main (){
	int v[] = {5, 4, 7, 7};
	int w[] = {5, 6, 8, 4};
	int dp[ITEMS+1][MAX_WEIGHT+1];
	knapsack(dp, v, w);
	return 0;
}