#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

bool check_palindrome_base2(ll val){
    ll ini = val;
    ll rev = 0;
    int bit;
    while (val > 0){
        bit = val % 2;
        rev = rev * 2 + bit;
        val = val / 2;
    }
    return (ini == rev);
}

int main(){
    ll m;
    cin >> m;
    ll cnt = 0;
    ll n = 1;
    while (cnt < m) {
        if (check_palindrome_base2(n)) {
            cnt++;
        }
        n++;
    }
    cout << n - 1 << endl;
}
