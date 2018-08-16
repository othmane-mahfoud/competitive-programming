#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> adj[1000];
vector<int> visited(1000, 0);
stack<int> order;

void topsort (int u){
    if (visited[u]) {
        return;
    }
    visited[u] = 1;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        topsort(v);
    }
    order.push(u);
}

int main(){
    int n, m;
    while(true){
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        for (int i = 0; i <= n; i++) {
            adj[i].clear();
        }
        int u, v;
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        for (int i = 0; i <= n; i++) {
            visited[i] = 0;
        }
        for(int i = 1; i <= n; i++){
            if(!visited[i]) {
                topsort(i);
            }
        }
        while(!order.empty()){
            if (order.size()==1)
                cout << order.top() << endl;
            else
                cout << order.top() << " ";
            order.pop();
        }
    }
    return 0;
}
