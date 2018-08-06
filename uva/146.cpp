#include <iostream>
#include <algorithm>

using namespace std;

int main (){
	string s;
	while(true){
		cin >> s;
		if (s.compare("#")==0)
		{
			return 0;
		}
		else{
			int l = s.length();
			if (next_permutation(&s[0],&s[0]+l))
			{
				cout << s << endl;
			}
			else{
				cout << "No Successor" << endl;
			}
		}
	}
	return 0;
}