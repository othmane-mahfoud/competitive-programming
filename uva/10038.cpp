#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main (){
	int n;
	while(cin >> n){
		int arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		int dif[n-1];
		for (int i = 0; i < n-1; ++i)
		{
			dif[i] = abs(arr[i+1] - arr[i]);
		}
		sort(dif, dif+n-1);
		int flag = 0;
		int count = 1;
		for (int i = 0; i < n-1; ++i)
		{
			if (dif[i] != count)
			{
				flag = 1;
				break;
			}
			count ++;
		}
		if (flag == 0)
		{
			cout << "Jolly" << endl;
		}
		else{
			cout << "Not jolly" << endl;
		}
	}
}