#include <iostream>
#include <algorithm>

#define n 8

using namespace std;

int main(){
	int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
	int dp[n+1];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++){
		int opt = INT_MIN;
		for (int k = 0; k < i; k++){
			if(prices[k] + dp[i-k] > opt)
				opt = prices[k] + dp[i-k-1];
		}	
		dp[i] = opt;	
	}
	for (int i = 0; i < n; ++i){
		cout << i + 1 << " | ";
	}
	cout << endl;
	for (int i = 1; i <= n; ++i){
		cout << dp[i] << " | ";
	}
	cout << endl;
}
