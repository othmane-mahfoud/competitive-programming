#include <iostream>
#include <algorithm>

using namespace std;

int main (){

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int salaries[3];
		for (int j = 0; j < 3; ++j)
		{
			cin >> salaries[j];	
		}
		sort(salaries, salaries+3);
		cout << "Case " << i + 1 << ": " << salaries[1] << endl; 
	}

}