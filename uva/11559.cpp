#include <iostream>
#include <algorithm>

using namespace std;

int main (){

	long long n, b, h, w;
	while(cin >> n >> b >> h >> w){
		long long bestPrice = 600000;
		for (int i = 0; i < h; ++i)
		{
			int p, a[w], flag = 0;
			cin >> p;
			for (int j = 0; j < w; ++j)
			{
				cin >> a[j];	
				if(a[j] >= n)
					flag = 1;
			}
			if(flag == 1){
				if(p * n < b && p * n < bestPrice){
					bestPrice = p * n;
				}
			}
		}
		if(bestPrice != 600000){
			cout << bestPrice << endl;
		}
		else{
			cout << "stay home" << endl;
		}
	}
}