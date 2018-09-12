#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll n, m;
    while(true) {
        cin >> n >> m;
        ll tasks = 0;
        ll l, r;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            cin >> l >> r;
//            int range = (((1 << (l - 1)) - 1) ^ ((1 << (r)) - 1));
//            cout << range << endl;
//            tasks = tasks | range;
            for (int j = l; j < r; j++) {
                if((tasks) & (1<<(j))){
//                    cout << "CONFLICT" << endl;
                    flag = true;
                    break;
                }
                else{
                    tasks |= (1<<j);
                }
            }
//            if (flag) {
//                break;
//            }
//            if (!flag) {
//                cout << "NO CONFLICT" << endl;
//            }
        }
        if(!flag){
            cout << "NO CONFLICT" << endl;
        }
        else
            cout << "CONFLICT" << endl;
    }
}
