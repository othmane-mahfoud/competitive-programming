#include <iostream>
#include <algorithm>

#define n 3
#define m 3

using namespace std;

int goldMax(int gold[n][m], int dp[n][m]){
	for (int j = m-1 ; j >= 0; j--){
		for (int i = n-1 ; i >= 0; i--){
			int right, rightup, rightdown;
			if (j == m-1)
				right = rightup = rightdown = 0;
			
			else if (i == 0){
				rightup = 0;
				right = dp[i][j+1];
				rightdown = dp[i+1][j+1];
			}

			else if(i == n-1){
				rightup = dp[i-1][j+1];
				right = dp[i][j+1];
				rightdown = 0;
			}

			else{
				rightup = dp[i-1][j+1];
				right = dp[i][j+1];
				rightdown = dp[i+1][j+1];
			}

			dp[i][j] = max(right, max(rightup, rightdown)) + gold[i][j];
		}
	}

	int maxGold = INT_MIN;
	for (int i = 0; i < n; ++i){
		if(dp[i][0] > maxGold)
			maxGold = dp[i][0];
	}
	return maxGold;
}

int main(){
	int gold[n][m] = {{1, 3, 3},
	                 {2, 1, 4},
	                 {0, 6, 4}};
	int dp[n][m];
	memset(dp, 0, sizeof(dp));
	cout << "The maximum amount of gold you can get from this mine is: " << goldMax(gold, dp) << endl;
	return 0;
}