#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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

int main(){
	ll n;
	while(true){
		cin >> n;
		if (n == 0)
		{
			return 0;
		}
		vector<ll> primes = eratosthenes(n);
		pair<ll, ll> res = make_pair(0, 0);
		ll diff = 0;
		int flag = 0;
		for (int i = 0; i < primes.size(); ++i)
		{
			for (int j = primes.size()-1; j >= i+1; --j)
			{
				if (primes[i] + primes[j] == n)
				{
					// if (primes[j] - primes[i] > diff)
					// {
						// diff = primes[j] - primes[i];
						res = make_pair(primes[i], primes[j]);
						flag = 1;
						break;

					// }
				}
			}
			if (flag == 1)
			{
				break;
			}
		}
		if (res.first == 0)
		{
			cout << "Goldbach's conjecture is wrong." << endl;
		}
		else
			cout << n << " = " << res.first << " + " << res.second << endl;
	}
	return 0;
}