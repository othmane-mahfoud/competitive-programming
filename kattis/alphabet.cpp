#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cmath>

using namespace std;

int main (){
	string s;
	cin >> s;
	int l = s.length();
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	int dp[27][l+1];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= 26; ++i){
		for (int j = 1; j <= l; ++j){
			if (alphabet[i-1]==s[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	int result = 26 - dp[26][l];
	cout << result << endl;
	return 0;
}