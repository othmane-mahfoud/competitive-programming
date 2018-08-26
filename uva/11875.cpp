#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n;
        cin >> n;
        vector<int> ages(n);
        for (int j = 0; j < n; j++) {
            cin >> ages[j];
        }
        int res = ages[n/2];
        cout << "Case " << i << ": " << res << endl;
    }
}
