#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    if (n==0 && m==0){
        cout << "Not a moose";
    }
    else if(n==m)
        cout << "Even " << n+m;
    else
        cout << "Odd " << 2 * max(n, m);
    return 0;
}
