#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
	while(true){
		int n, m, s;
		cin >> n >> m >> s;
		getchar();
		if (n == 0 && m == 0 && s == 0){
			break;
		}
		char graph[n][m];
		int x, y;
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j){
				cin >> graph[i][j];
				if (graph[i][j] == 'N' || graph[i][j] == 'S' || graph[i][j] == 'O' || graph[i][j] == 'L'){
					x = i;
					y = j;
				}
			}
			getchar();
		}
		string inst;
		cin >> inst;
		int c = 0;
		for (int i = 0; i < inst.length(); ++i){
			if (inst[i] == 'D'){
				if (graph[x][y] == 'N')
					graph[x][y] = 'L';
				else if (graph[x][y] == 'S')
					graph[x][y] = 'O';
				else if (graph[x][y] == 'O')
					graph[x][y] = 'N';
				else
					graph[x][y] = 'S';
			}
		    else if (inst[i] == 'E'){
				if (graph[x][y] == 'N')
					graph[x][y] = 'O';
				else if (graph[x][y] == 'S')
					graph[x][y] = 'L';
				else if (graph[x][y] == 'O')
					graph[x][y] = 'S';
				else
					graph[x][y] = 'N';
			}
			else{
				if (graph[x][y] == 'N'){
					if (x != 0 && graph[x-1][y] != '#'){
						if (graph[x-1][y] == '*'){
							c++;
						}
						graph[x-1][y] = graph[x][y];
						graph[x][y] = '.';
						x--;
					}
				}
				else if (graph[x][y] == 'S'){
					if (x != n-1 && graph[x+1][y] != '#'){
						if (graph[x+1][y] == '*'){
							c++;
						}
						graph[x+1][y] = graph[x][y];
						graph[x][y] = '.';
						x++;
					}
				}
				else if (graph[x][y] == 'O'){
					if (y != 0 && graph[x][y-1] != '#'){
						if (graph[x][y-1] == '*'){
							c++;
						}
						graph[x][y-1] = graph[x][y];
						graph[x][y] = '.';
						y--;
					}
				}
				else {
					if (y != m-1 && graph[x][y+1] != '#'){
						if (graph[x][y+1] == '*'){
							c++;
						}
						graph[x][y+1] = graph[x][y];
						graph[x][y] = '.';
						y++;
					}
				}
			}
		}
		cout << c << endl;
	}
}