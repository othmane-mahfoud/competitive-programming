#include<iostream>
using namespace std;

int n=4;
int dist[10][10] = { { 0, 10, 15, 20 },
                 { 10, 0, 35, 25 },
                 { 15, 35, 0, 30 },
                 { 20, 25, 30, 0 } };
int VISITED_ALL = (1<<n) -1;

int dp[16][4];


int  tsp(int mask,int pos){
    
    if(mask==VISITED_ALL){
        return dist[pos][0];
    }
    if(dp[mask][pos]!=-1){
        return dp[mask][pos];
    }
    
    //Now from current node, we will try to go to every other node and take the min ans
    int ans = INT_MAX;
    
    //Visit all the unvisited cities and take the best route
    for(int city=0;city<n;city++){
        
        if((mask&(1<<city))==0){
            
            int newAns = dist[pos][city] + tsp( mask|(1<<city), city);
            ans = min(ans, newAns);
        }
        
    }
    
    return dp[mask][pos] = ans;
}

int main(){
    /* init the dp array */
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            dp[i][j] = -1;
        }
    }
    cout << "Travelling Salesman Distance is " << tsp(1,0) << endl;
    
    return 0;
}
