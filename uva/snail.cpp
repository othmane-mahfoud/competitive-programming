#include<iostream>
#include<algorithm>

using namespace std;

int main (){
	int h, u, d, f;
	while(true){
		cin >> h >> u >> d >> f;
		if(h==0){
			break;
		}
		else{
			int n = 0;
			double totalHeight = 0.0;
			double fatigue = (double)(u * (double)(f/100.0));
			while(true){
				// cout << "Day: " << n+1;
				double distanceToClimb = (double)(u - (double)(fatigue * n));
				if (distanceToClimb > 0)
				{
					// cout << " | Distance climbed: " << distanceToClimb;
					totalHeight += distanceToClimb;
				}
				// cout << " | Distance after climbing: " << totalHeight;
				if (totalHeight > h)
				{
					cout << "success on day " << n+1 << endl;
					break;
				}
				totalHeight -= d;
				// cout << " | Distance after sliding: " << totalHeight << endl;
				if (totalHeight < 0)
				{
					cout << "failure on day " << n+1 << endl;
					break;
				}
				n++;
			}
		}
	}
}