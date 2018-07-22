//Not solved

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main (){
	while(true){
		cin >> n;
		vector<int> v;
		stack<int> s;
		int in;
		for (int i = 0; i < n; ++i)
		{
			v.push_back(i+1);
			cin >> in;
			if(in == 0)
				break;
			else
				s.push(in);
		}
	}
	return 0;
}