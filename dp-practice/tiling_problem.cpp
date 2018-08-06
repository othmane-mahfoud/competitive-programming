#include <iostream>
#include <algorithm>

using namespace std;

int countWays(int n, int dp[]){
	if (n==1 || n==2)
		return n;
	else if (dp[n] != 0){
		return dp[n];
	}
	else {
		dp[n] = countWays(n-1, dp) + countWays(n-2, dp);
		return dp[n];
	}
}

int main(){
	int n;
	cin >> n;
	int dp[n+1];
	memset(dp, 0, sizeof(dp));
	dp[1] = 1;
	dp[2] = 2;
	cout << "The number of ways to tile a 2xn floor with a 2x1 tile is: " << countWays(n, dp) << endl;
}