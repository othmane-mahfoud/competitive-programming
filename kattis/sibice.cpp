#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, w, h;
    cin >> n >> w >> h;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        if (m > w && m > h && m > sqrt(h*h + w*w)) {
            cout << "NE" << endl;
        }
        else
            cout << "DA" << endl;
    }
    return 0;
}
