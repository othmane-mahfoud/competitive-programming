#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main (){
	string s;
	while(getline(cin, s)){
		list<char> l;
		list<char>::iterator it;
		char c;
		it = l.begin();
		int i = 0;
		for(int i = 0; i < s.length(); i++){
			if (s[i] == '['){
				it = l.begin();
			}
			else if (s[i] == ']'){
				it = l.end();
			}
			else {
				l.insert(it, s[i]);
			}
		}
		for (it = l.begin(); it != l.end(); ++it)
			cout << *it;
		cout << endl;
	}
	return 0;
}