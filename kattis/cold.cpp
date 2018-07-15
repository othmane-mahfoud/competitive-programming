#include <iostream>

using namespace std;

int main (){
	int n;
	cin >> n;
	int temp;
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		if(temp < 0)	
			count++;
	}
	cout << count << endl;
}