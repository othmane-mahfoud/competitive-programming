#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[1000];
vector<int> side(1000, -1);
bool is_bipartite = true;

void check_bipartite(int u){
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (side[v] == -1) {
            side[v] = 1 - side[u];
            check_bipartite(v);
        }
        else if (side[u] == side[v]) {
            is_bipartite = false;
        }
    }
}

int main(){
    int n;
    while (true) {
        cin >> n;
        if(n == 0)
            break;
        int l;
        cin >> l;
        for (int i = 0; i < l; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int u = 0; u < n; u++) {
            if(side[u] == -1){
                side[u] = 0;
                check_bipartite(u);
            }
        }
        if (is_bipartite) {
            cout << "BICOLORABLE." << endl;
        }
        else{
            cout << "NOT BICOLORABLE." << endl;
        }
        for (int i = 0; i < n; i++) {
            adj[i].clear();
            side[i] = -1;
        }
        is_bipartite = true;
    }
}
