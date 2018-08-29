#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    vector<pair<ll, ll> > vp(n);
    ll m;
    for(ll i = 0; i < n; i++){
        cin >> v[i];
        vp[i] = make_pair(v[i], i);
    }
    sort(vp.begin(), vp.end());
    ll a = 0;
    ll b = n-1;
    for (ll i = 0; i < n; i++) {
        if (i % 2 == 0) {
            ll l = 0;
            ll r = n - 1;
            ll m;
            while (l <= r){
                m = l + (r-l)/2;
                if (vp[m].first == a + 1)
                    break;
                if (vp[m].first < a + 1)
                    l = m + 1;
                else
                    r = m - 1;
            }
            ll j = vp[m].second;
            ll temp;
            for (ll k = j; k > a; k--) {
                temp = v[k - 1];
                v[k - 1] = v[k];
                v[k] = temp;
            }
            vp[m] = make_pair(a+1, a);
            cout << j - a << endl;
            a++;
        }
        else{
            ll l = 0;
            ll r = n - 1;
            ll m;
            while (l <= r){
                m = l + (r-l)/2;
                if (vp[m].first == b + 1)
                    break;
                if (vp[m].first < b + 1)
                    l = m + 1;
                else
                    r = m - 1;
            }
            ll j = vp[m].second;
            ll temp;
            for (ll k = j; k < b; k++) {
                temp = v[k + 1];
                v[k + 1] = v[k];
                v[k] = temp;
            }
            vp[m] = make_pair(b+1, b);
            for (ll k = 0; ll k = ; <#increment#>) {
                <#statements#>
            }
            cout << b - j << endl;
            b--;
        }
    }
}
