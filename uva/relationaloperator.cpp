#include <iostream>

using namespace std;

int main (){

	int t, x, y;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cin >> x >> y;
		if(x>y)
			cout << ">" << endl;
		else if(x<y)
			cout << "<" << endl;
		else if(x==y)
			cout << "=" << endl;
	}

}