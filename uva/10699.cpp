#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// Prime numbers generation using sieve of eratosthenes

vector<ll> eratosthenes(ll n){
    bool *isMarked = new bool[n+1];
    memset(isMarked, 0, n+1);
    vector<ll> primes;
    ll i = 2;
    for(; i*i <= n; ++i)
        if (!isMarked[i]) {
            primes.push_back(i);
            for(ll j = i; j <= n; j += i)
                isMarked[j] = true;
        }
    for (; i <= n; i++)
        if (!isMarked[i])
            primes.push_back(i);
    return primes;
}

// generating prime factors of a number

map<ll, ll> factor(ll N) {
    vector<ll> primes;
    primes = eratosthenes(static_cast<ll>(sqrt(N+1)));
    map<ll, ll> factors;
    for(ll i = 0; i < primes.size(); ++i){
        ll prime = primes[i], power = 0;
        while(N % prime == 0){
            power++;
            N /= prime; }
        if(power > 0){
            factors[prime] = power;
        } }
    if (N > 1) {
        factors[N] = 1;
    }
    return factors;
}

int main(){
    ll n;
    while(true){
    	cin >> n;
    	if (n==0)
    	{
    		break;
    	}
    	map<ll, ll> factors = factor(n);
    	int cnt = 0;
    	for (ll i = 0; i < factors.size(); ++i)
    	{
    		if (factors[i] != 0)
    		{
    			cnt++;
    		}
    	}
    	cout << n << " : " << cnt << endl;
    }
}
