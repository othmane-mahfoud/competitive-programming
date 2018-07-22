#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main (){
	// freopen("out.txt", "w", stdout);
	long t;
	while(true){
		cin >> t;
		multiset<long> s;
		if (t==0)
		{
			break;
		}
		long sum = 0;
		for (long i = 0; i < t; ++i)
		{
			long n;
			cin >> n;
			long m;
			for (long i = 0; i < n; ++i)
			{
				cin >> m;
				s.insert(m);
			}
			multiset<long>::iterator it;
			it = s.begin();
			multiset<long>::reverse_iterator rit;
			rit = s.rbegin();
			sum += (*rit - *it); 
			multiset<long>::iterator toErase;
			toErase = s.find(*it);
			s.erase(toErase);
			toErase = s.find(*rit);
			s.erase(toErase);
		}
		cout << sum << endl;
	}
}