#include <iostream>
#include <algorithm>

#define n 16

using namespace std;

int min (int a, int b){
	return a < b ? a : b;
}

int main(){
	int d[] = {1, 5, 12, 25};
	int c[n+1];
	memset(c, 0, sizeof(c));
	for (int i = 1; i <= n; ++i){
		int minimum = INT_MAX;
		int last_denom = 1;
		for (int j = 0; j < 4 && d[j] <= i; j++){
			minimum = min(minimum, c[i-d[j]]+1);
			if (minimum == c[i-d[j]]+1)
				last_denom = d[j];
			else
				last_denom = 1;
		}
		c[i] = minimum;
	}
	for (int i = 1; i <= n; ++i)
		cout << i << " | ";
	cout << endl;
	for (int i = 1; i <= n; ++i)
		cout << c[i] << " | ";
	cout << endl;
}