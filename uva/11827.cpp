#include <bits/stdc++.h>

using namespace std;

int gcd (int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main(){
    int t;
    string s;
    cin >> t;
    getline(cin, s);
    int v[99];
    while (t--) {
        getline(cin, s);
        istringstream is(s);
        int n = 0;
        while (is>>v[n]) {
            n++;
        }
        int max_gcd = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                max_gcd = max(max_gcd, gcd(v[i], v[j]));
            }
        }
        cout << max_gcd << endl;
    }
    return 0;
}
