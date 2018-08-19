#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>

typedef long long ll;

using namespace std;

int main(){
    ll n, m;
    while (true) {
        cin >> n >> m;
        if(n == 0 && m == 0)
            break;
        vector<ll> heads;
        vector<ll> knights;
        ll temp;
        for (ll i = 0; i < n; i++) {
            cin >> temp;
            heads.push_back(temp);
        }
        for (ll i = 0; i < m; i++) {
            cin >> temp;
            knights.push_back(temp);
        }
        sort(heads.begin(), heads.end());
        sort(knights.begin(), knights.end());
        ll h = 0;
        ll k = 0;
        ll price = 0;
        while (h < heads.size() && k < knights.size()) {
            if (knights[k] >= heads[h]) {
                h++;
                price += knights[k];
            }
            k++;
        }
        if (h < heads.size()) {
            cout << "Loowater is doomed!" << endl;
        }
        else{
            cout << price << endl;
        }
    }
    return 0;
}
