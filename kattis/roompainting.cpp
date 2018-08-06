#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(){
	ll n, m;
	cin >> n >> m;
	ll cans[n];
	ll needs[m];
	for (ll i = 0; i < n; ++i){
		cin >> cans[i];
	}
	for (ll i = 0; i < m; ++i){
		cin >> needs[i];
	}
	sort(cans, cans+n);
	ll sum = 0;
	for (ll i = 0; i < m; ++i){
		for (ll j = 0; j < n; ++j){
			if (cans[j] >= needs[i]){
				sum += cans[j];
				break;
			}
		}
	}
	ll needed = 0;
	for (ll i = 0; i < m; ++i){
		needed += needs[i];
	}
	cout << sum - needed << endl;
}