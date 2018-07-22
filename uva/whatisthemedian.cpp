#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main (){
	vector<long long> v;
	long long n;
	while(cin >> n){
		v.push_back(n);
		sort(v.begin(), v.end());
		if (v.size()==1)
		{
			cout << v[0] << endl;
		}
		else if (v.size()%2==0){
			long long first = v.size()/2 - 1;
			long long second = v.size()/2;
			long long median = (v[first]+v[second])/2;
			cout << median << endl;
		}
		else {
			long long indx = v.size()/2;
			cout << v[indx] << endl;
		}
	}
	return 0;
}