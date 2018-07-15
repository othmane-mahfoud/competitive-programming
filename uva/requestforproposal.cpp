#include<iostream>
#include<algorithm>

using namespace std;

void dswap(double *xp, double *yp)
{
    double temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sswap(string *xp, string *yp)
{
    string temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void iswap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int main (){
	int n, p;
	int rfp = 1;
	while(true){
		cin >> n >> p;
		if(n==0 && p==0){
			break;
		}
		else{
			string temp;
			for (int i = 0; i < n; ++i)
			{
				cin >> temp;
			}
			int propId[p];
			string name[p];
			double price[p];
			int check;
			double compliance[p];
			for (int i = 0; i < p; ++i)
			{
				cin >> name[i] >> price[i] >> check;
				propId[i] = i;
				compliance[i] = (double)check/(double)n;
				string temp2;
				for (int j = 0; j < check; ++j)
				{
					cin >> temp2;
				}
			}
			
			for (int i = 0; i < p-1; i++){     
		        // Last i elements are already in place  
		        for (int j = 0; j < p-i-1; j++){
		           if (compliance[j] > compliance[j+1]){
		              dswap(&compliance[j], &compliance[j+1]);
		              dswap(&price[j], &price[j+1]);
		              sswap(&name[j], &name[j+1]);
		              iswap(&propId[j], &propId[j+1]);
		           }
				}
			}
			
			int chosenId = propId[p-1];
			string chosenName = name[p-1];
			int i = p-1;

			while(compliance[i]==compliance[i-1]){
				if (price[i]>price[i-1])
				{
					chosenId = propId[i-1];
					chosenName = name[i-1];
					i--;
				}
			}

			cout << "RFP #" << rfp << endl;
			cout << chosenName << endl;
		}
		rfp++;
	}
}
