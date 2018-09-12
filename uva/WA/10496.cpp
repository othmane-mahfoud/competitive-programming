#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//int  tsp(int mask,int pos){
//
//    if(mask==VISITED_ALL){
//        return dist[pos][0];
//    }
//    if(dp[mask][pos]!=-1){
//        return dp[mask][pos];
//    }
//
//    //Now from current node, we will try to go to every other node and take the min ans
//    int ans = INT_MAX;
//
//    //Visit all the unvisited cities and take the best route
//    for(int city=0;city<n;city++){
//
//        if((mask&(1<<city))==0){
//
//            int newAns = dist[pos][city] + tsp( mask|(1<<city), city);
//            ans = min(ans, newAns);
//        }
//
//    }
//
//    return dp[mask][pos] = ans;
//}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int dist[n][m];
        int VISITED_ALL = (1<<n) -1;
        int dp[n*m][n];
        for(int i=0;i<(1<<n);i++){
            for(int j=0;j<m;j++){
                dp[i][j] = -1;
            }
        }
        int sx, sy;
        cin >> sx >> sy;
        int n_of_beepers;
        cin >> n_of_beepers;
        for (int i=0; i < n_of_beepers; i++) {
            int x, y;
            cin >> x >> y;
            dist[x-1][y-1] = abs(sx - x) + abs(sy - y);
        }
        for (int i = 0 ; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << dist[i][j] << " ";
            }
            cout << endl;
        }
    }
//    cout << "Travelling Salesman Distance is " << tsp(1,0) << endl;
    
    return 0;
}
