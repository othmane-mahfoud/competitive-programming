#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <string.h>

using namespace std;

struct union_find{
	vector<int> parent;

	union_find(int n){
		parent = vector<int>(n);
		for (int i = 0; i < n; ++i)
		{
			parent[i] = i;
		}
	}

	int find(int x){
		if (parent[x] == x){
			return x;
		}
		else{
			parent[x] = find(parent[x]);
			return parent[x];
		}		
	}

	void unite(int x, int y){
		parent[find(x)] = find(y);
	}
};

int main () {
	// freopen("out.txt", "w", stdout);
	map<char,int> m;
	m['A'] = 0;
	m['B'] = 1;
	m['C'] = 2;
	m['D'] = 3;
	m['E'] = 4;
	m['F'] = 5;
	m['G'] = 6;
	m['H'] = 7;
	m['I'] = 8;
	m['J'] = 9;
	m['K'] = 10;
	m['L'] = 11;
	m['M'] = 12;
	m['N'] = 13;
	m['O'] = 14;
	m['P'] = 15;
	m['Q'] = 16;
	m['R'] = 17;
	m['S'] = 18;
	m['T'] = 19;
	m['U'] = 20;
	m['V'] = 21;
	m['W'] = 22;
	m['X'] = 23;
	m['Y'] = 24;
	m['Z'] = 25;
	while(true){
		int n;
		cin >> n;
		union_find uf(26);
		int t;
		cin >> t;
		string hab;
		cin >> hab;
		hab.c_str();
		int h = m[hab[0]];
		int a = m[hab[1]];
		int b = m[hab[2]];
		uf.unite(a, b);
		uf.unite(a, h);
		int years = -1;
		for (int i = 0; i < t; ++i){
			string s;
			cin >> s;
			s.c_str();
			int x, y;
			x = m[s[0]];
			y = m[s[1]];
			uf.unite(x, y);
			if (((x != h && x != a && x != b && uf.find(x)==uf.find(h)) || (y != h && y != a && y != b && uf.find(y)==uf.find(h))) && years == -1)
			{
				years = i + 1;
				cout << "WAKE UP IN, " << years << ", YEARS" << endl;
			}
		}
		if (years == -1){
			cout << "THIS BRAIN NEVER WAKES UP" << endl;
		}
		string temp;
		getline(cin, temp);
	}
	
}










