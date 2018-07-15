#include <iostream>
#include <algorithm>

using namespace std;

int main (){
	int n, t;
	cin >> n >> t;
	int sum = 0, count = 0, temp;
	int i;
	for (i = 0; i < n; ++i)
	{
		cin >> temp;
		sum += temp;
		if(sum>t){
			break;
		}
	}
	cout << i << endl;
}