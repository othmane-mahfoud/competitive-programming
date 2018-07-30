#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

int max (int a, int b){
	return a >= b ? a : b;
}

int main(){
	string s1;
	string s2;
	cin >> s1;
	cin >> s2;
	vector<char> lcs;
	int rows = s1.length() + 1;
	int cols = s2.length() + 1;
	int dp[rows][cols];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i < rows; ++i){
		for (int j = 1; j < cols; ++j){
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	cout << "the lcs length is: " << dp[rows-1][cols-1] << endl;
	return 0;
}