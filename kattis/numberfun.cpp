#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a,b,c;
        cin >> a >> b >> c;
        if (a + b == c || a - b == c || b - a == c || a * b == c || c * b == a || c * a == b) {
            cout << "Possible" << endl;
        }
        else
            cout << "Impossible" << endl;
    }
    return 0;
}
