#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	while(cin >> n){
		if (n == 0)
		{
			return 0;
		}
		queue<int> q;
		stack<int> s;
		priority_queue<int> pq;
		vector<int> v;
		bool isStack = true;
		bool isQueue = true;
		bool isPq = true;
		for (int i = 0; i < n; ++i)
		{
			int op;
			int x;
			cin >> op >> x;
			if(op==1){
				q.push(x);
				s.push(x);
				pq.push(x);
			}
			else{
				if (x != q.front())
				{
					isQueue = false;
				}
				if(x != s.top()){
					isStack = false;
				}
				if (x != pq.top())
				{
					isPq = false;
				}
				q.pop();
				s.pop();
				pq.pop();
			}
		}
		if ((isStack && isQueue && isPq) || (isStack && isQueue) || (isQueue && isPq) || (isStack && isPq))
		{
			cout << "not sure" << endl;
		}
		else if(isQueue){
			cout << "queue" << endl;
		}
		else if(isStack){
			cout << "stack" << endl;
		}
		else if(isPq){
			cout << "priority queue" << endl;
		}
		else{
			cout << "impossible" << endl;
		}
	}
	return 0;
}