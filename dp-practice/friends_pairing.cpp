#include <iostream>
#include <algorithm>

using namespace std;

int pairWays(int n, int dp[]){
	for (int i = 1; i <= n; ++i){
		if (i <= 2)
			dp[i] = i;
		else
			dp[i] = dp[i-1] + (i-1) * dp[i-2];
	}
	return dp[n];
}

int main(){
	int n;
	cin >> n;
	int dp[n+1];
	memset(dp, 0, sizeof(dp));
	cout << "the number of ways to pair up friends is: ";
	cout << pairWays(n, dp) << endl; 
}