#include <bits/stdc++.h>

using namespace std;

int lcs (string s1, string s2) {
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
    return dp[rows-1][cols-1];
}

int main(){
    string s1;
    string s2;
    int case_num = 1;
    while (true) {
        getline(cin, s1);
        if (s1.compare("#") == 0) {
            return 0;
        }
        getline(cin, s2);
        cout << "Case #" << case_num << ": you can visit at most " << lcs(s1, s2) << " cities." << endl;
        case_num++;
    }
    return 0;
}

