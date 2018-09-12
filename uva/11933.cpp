#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
    ll num;
    while (true) {
        cin >> num;
        if (num == 0) break;
        ll pos = 1;
        ll a = 0;
        ll b = 0;
        for (int i = 0; i < 50; i++) {
            if ((num>>i)&1) {
                if (pos % 2 == 0) {
                    b |= (1 << i);
                }
                else{
                    a |= (1 << i);
                }
                pos++;
            }
//            if ((i | (num - i)) == num) {
//                cout << i << " " << num - i << endl;
//                break;
//            }
        }
        cout << a << " " << b << endl;
    }
    return 0;
}
