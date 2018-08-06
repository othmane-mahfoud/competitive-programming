#include <iostream>
#include <algorithm>

using namespace std;

int main (){

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int n;
		cin >> n;
		int arr[n];
		for (int j = 0; j < n; ++j)
		{
			cin >> arr[j];
		}
		cout << "Case " << i+1 << ": " << *max_element(arr, arr+n) << endl;
	}

}