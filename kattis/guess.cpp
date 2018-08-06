#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	int lo = 1;
	int hi = 1000;
	while(lo <= hi){
		int mid = lo + (hi-lo)/2;
		cout << mid << endl;
		string ans;
		cin >> ans;
		if (ans.compare("correct")==0){
			return 0;
		}
		else if (ans.compare("lower")==0){
			hi = mid - 1;
		}
		else{
			lo = mid + 1;
		}
	}
	return 0;
}