#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct union_find{
	
	vector<int> parent;
	vector <int> size;

	union_find(int n){
		parent = vector<int>(n);
		size = vector<int>(n);
		for (int i = 0; i < n; i++){
			parent[i] = i;
			size[i] = 1;
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
		size[parent[find(x)]] += size[find(y)];
	}

	int count(int x){
		return size[find(x)];
	}
	
};

int main () {

	int x,y;
	union_find uf(5);
	uf.unite(3, 4);
	uf.unite(0, 1);
	
	//Test union and find

	while(true){
		cin >> x >> y;
		if(x > 4 || y > 4) break;
		else if (uf.find(x)==uf.find(y))
		{
			cout << "Connected" << endl;
		}
		else{
			cout << "Not connected" << endl;
		}
	}

	//Test count

	while(true){
		cin >> x;
		if(x > 4) break;
		cout << uf.count(x) << endl;
	}
	
}