// #include <iostream>
// #include <cmath>
// #include <algorithm>
// #include <stack>

// using namespace std;

// typedef long long ll; 

// int main(){
// 	double temp; 
// 	ll n;
// 	while (cin >> temp >> n){
// 		ll v[n];
// 		ll w[n];
// 		temp = floor(temp);
// 		ll c = (int)temp; 
// 		ll dp[n+1][c+1];
// 		for (ll i = 0; i < n; ++i){
// 			cin >> v[i] >> w[i];
// 		}
// 		//fill memo table
// 		for (ll i = 0; i <= n; ++i){
// 			for (ll m = 0; m <= c; ++m){
// 				if (i == 0 || m == 0)
// 					dp[i][m] = 0;
// 				else if(w[i-1] < m)
// 					dp[i][m] = dp[i-1][m];
// 				else
// 					dp[i][m] = max(v[i-1] + dp[i-1][m-w[i-1]], dp[i-1][m]);
// 			}
// 		}
// 		//time to chbandellakh
// 		stack<ll> s;
// 		ll i = n;
// 		ll m = c;
// 		ll nb = 0;
// 		while(true){
// 			if (dp[i][m] == dp[i-1][m]){
// 				break;
// 			}
// 			else{
// 				nb++;
// 				s.push(i-1);
// 				m -= w[i-1];
// 				i--;
// 			}
// 		}
// 		cout << nb << endl;
// 		while(!s.empty()){
// 			cout << s.top() <<" ";
// 			s.pop();
// 		}
// 		cout << endl;
// 	}
// 	return 0;
// }

#include <stdio.h>
#include <vector>

using namespace std;

struct Object {
  Object(int i_, int v, int w) : i(i_), value(v), weight(w) {}
  int i, value, weight;
};

void knapsack(int cap, const vector<Object> &objs, vector<int> &taken_inds) {
  vector<vector<int> > values(objs.size() + 1, vector<int>(cap + 1, 0));
  vector<vector<bool> > taken(objs.size(), vector<bool>(cap + 1, false));
  for (auto &item : objs) {
    for (int c = 0; c <= cap; ++c) {
      if (c < item.weight ||
          values[item.i][c - item.weight] + item.value < values[item.i][c]) {
        values[item.i + 1][c] = values[item.i][c];
      } else {
        values[item.i + 1][c] = values[item.i][c - item.weight] + item.value;
        taken[item.i][c] = true;
      }
    }
  }

  int c = cap;
  for (int i = objs.size() - 1; i >= 0; --i) {
    if (taken[i][c]) {
      taken_inds.push_back(i);
      c -= objs[i].weight;
    }
  }
}

int main() {
  float C;
  int N, v, w;
  while (scanf("%f %d", &C, &N) == 2) {
    vector<Object> objs;
    for (int i = 0; i < N; ++i) {
      scanf("%d %d", &v, &w);
      objs.emplace_back(i, v, w);
    }

    vector<int> taken;
    knapsack((int)C, objs, taken);
    
    printf("%lu\n", taken.size());
    for (size_t i = 0; i < taken.size(); ++i)
      printf("%d ", taken[i]);
    printf("\n");
  }
}
