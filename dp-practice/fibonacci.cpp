#include <iostream>
#include <algorithm>

using namespace std;

int fibonacci(int n, int mem[]){
	if(n==0 || n==1){
		return 1;
	}
	else if (mem[n]!=0){
		return mem[n];
	}
	else {
		mem[n] = fibonacci(n-1, mem) + fibonacci(n-2, mem);
		return mem[n];
	}
}

int main(){
	int n;
	cout << "enter a number: " << endl;
	cin >> n;
	int mem[n];
	memset(mem, 0, sizeof(mem));
	cout << fibonacci(n-1, mem) << endl;
	return 0;
}