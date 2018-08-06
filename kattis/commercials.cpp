#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	int n, p;
	cin >> n >> p;
	int a[n];
	int dp[n];
	int temp;
	for (int i = 0; i < n; ++i){
		cin >> temp;
		temp -= p;
		a[i] = temp;
	}
	for (int i = 0; i < n; ++i){
		if (i==0){
			dp[i] = a[i];
		}
		else{
			dp[i] = max(dp[i-1]+a[i], a[i]);
		}
	}
	sort(dp, dp+n);
	cout << dp[n-1] << endl;
}