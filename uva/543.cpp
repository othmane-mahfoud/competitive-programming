#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool *isMarked = new bool[1000001];

vector<ll> eratosthenes(ll n){
    memset(isMarked, 0, n+1);
    vector<ll> primes;
    ll i = 2;
    for(; i*i <= n; ++i)
        if (!isMarked[i]) {
            primes.push_back(i);
            for(ll j = i*i; j <= n; j += i)
                isMarked[j] = true;
        }
    for (; i <= n; i++)
        if (!isMarked[i])
            primes.push_back(i);
    return primes;
}

int main(){
	ll n;
    vector<ll> primes = eratosthenes(1000000);
	while(true){
		cin >> n;
		if (n == 0){
			return 0;
		}
		
		ll diff = 0;
		int flag = 0;
		for (int i = 0; i < primes.size(); ++i){
            if (!isMarked[n - primes[i]]) {
                cout << n << " = " << primes[i] << " + " << n - primes[i] << endl;
                break;
            }
		}
	}
	return 0;
}
