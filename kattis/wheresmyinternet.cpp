#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

#define MAXN 200100

int p[MAXN];

int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

void unite(int x, int y) {
    p[find(x)] = find(y);
}

int main(){
	for (ll i = 0; i < MAXN; ++i)
	{
		p[i] = i;
	}
	ll n,m;
	cin >> n >> m;
	for (ll i = 0; i < m; ++i)
	{
		ll a,b;
		cin >> a >> b;
		a--;
		b--;
		unite(a, b); 
	}
	int flag = 0; 
	for (ll i = 0; i < n; ++i)
	{
		if (find(i)!=find(0))
		{
			flag = 1;
			cout << i + 1 << endl;
		}
	}
	if (flag == 0)
	{
		cout << "Connected" << endl;
	}
	return 0;
} 