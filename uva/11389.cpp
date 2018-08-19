#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

typedef long long ll;

using namespace std;

int main(){
    ll n, d, r;
    while (true) {
        cin >> n >> d >> r;
        if(n == 0 && d==0 && r==0)
            break;
        priority_queue<ll, vector<ll>, greater<ll> > morning;
        priority_queue<ll> night;
        ll t;
        for (ll i = 0; i < n; i++) {
            cin >> t;
            morning.push(t);
        }
        for (ll i = 0; i < n; i++) {
            cin >> t;
            night.push(t);
        }
        ll overtime = 0;
        for (ll i = 0; i < n; i++) {
            ll total_time = morning.top() + night.top();
            if(total_time > d)
                overtime += (total_time - d) * r;
            morning.pop();
            night.pop();
        }
        cout << overtime << endl;
    }
    return 0;
}
