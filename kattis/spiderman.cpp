#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        int dp[m];
        int dist[m];
        int sum = 0;
        for (int j = 0; j < m; j++) {
            cin >> dist[j];
            sum += dist[j];
        }
        if (sum % 2 != 0) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        for (int j = 0; j < m; j++) {
            if (j == 0) {
                dp[j] = dist[j];
            }
            else{
                dp[j] = min(dp[j-1] + dist[j], dp[j-1] - dist[j] < 0 ? INT_MAX : dp[j-1] - dist[j]);
            }
        }
        if (dp[m-1] != 0) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        cout << "U";
        for (int j = 1; j < m; j++) {
            if (dp[j] > dp[j-1])
                cout << "U";
            else
                cout << "D";
        }
        cout << endl;
    }
}
