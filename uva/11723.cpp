#include <bits/stdc++.h>

using namespace std;

int main(){
    int r, n;
    int t = 1;
    while(true){
        cin >> r >> n;
        if(r == 0 && n == 0)
            break;
        if (n + n*26 < r) {
            cout << "Case " << t << ": impossible" << endl;
            t++;
            continue;
        }
        if (r <= n) {
            cout << "Case " << t << ": 0" << endl;
            t++;
            continue;
        }
        for (int i = 1; i <= 26; i++) {
            if (n + n*i >= r) {
                cout << "Case " << t << ": " << i << endl;
                break;
            }
        }
        t++;
    }
    return 0;
}
