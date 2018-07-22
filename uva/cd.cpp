#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n,m;
	while(true){
		cin >> n >> m;
		if (n==0 && m==0)
		{
			return 0;
		}
		int first[n];
		int second[m];
		vector<int> v(n+m);
		vector<int>::iterator it;
		for (int i = 0; i < n; ++i)
		{
			int x;
			cin >> first[i];
		}
		for (int i = 0; i < m; ++i)
		{
			int x;
			cin >> second[i];
		}
		sort(first, first+n);
		sort(second, second+m);
		it = set_intersection(first, first+n, second, second+m, v.begin());
		v.resize(it-v.begin());
		cout << (v.size()) << endl;
	}
	return 0;
}