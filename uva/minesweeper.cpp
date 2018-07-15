#include<iostream>
#include<algorithm>

using namespace std;

int main (){
	int t = 1;
	while(true){
		int n, m;
		cin >> n >> m;
		if(n==0 && m==0){
			break;
		}
		else{
			char g1[n+2][m+2];
			for (int i = 0; i < n+2; ++i){
				for (int j = 0; j < m+2; ++j)
				{
					g1[i][j] = '.';
				}
			}
			for (int i = 1; i < n+1; ++i){
				for (int j = 1; j < m+1; ++j)
				{
					cin >> g1[i][j];
				}
			}
			if (t!=1)
			{
				cout << endl;
			}
			cout << "Field #" << t << ":" << endl;
			for (int i = 1; i < n+1; ++i){
				for (int j = 1; j < m+1; ++j){
					int sum = 0;
					if (g1[i][j]=='*')
					{
						cout << "*";
					}
					else{
						if(g1[i-1][j-1]=='*')
							sum++;
						if(g1[i-1][j]=='*')
							sum++;
						if(g1[i-1][j+1]=='*')
							sum++;
						if(g1[i][j-1]=='*')
							sum++;
						if(g1[i][j+1]=='*')
							sum++;
						if(g1[i+1][j-1]=='*')
							sum++;
						if(g1[i+1][j]=='*')
							sum++;
						if(g1[i+1][j+1]=='*')
							sum++;
						cout << sum;
					}
				}
				cout << endl;
			}
		}
		t++;
	}
	return 0;
}