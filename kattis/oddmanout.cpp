#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int g;
    for (int j = 1; j <= n; j++) {
        cin >> g;
        vector<int> v(g);
        for (int i = 0; i < g; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < g; i+=2) {
            if (v[i] != v[i+1]) {
                cout << "Case #" << j << ": " << v[i] << endl;
                break;
            }
        }
    }
}
