#include <iostream>

using namespace std;

int main (){
	int duration, numOfDepRecords;
	float downPayment, amount;
	// while (true) {
		cin >> duration >> downPayment >> amount >> numOfDepRecords;
		// if (duration < 0)
		// {
		// 	break;
		// }
		float depreciationRecords[duration];
		for (int i = 0; i < numOfDepRecords; ++i)
		{
			int monthNumber;
			float depreciationPercentage;
			cin >> monthNumber >> depreciationPercentage;
			for (int j = duration - 1; j >= monthNumber; --j)
			{
				depreciationRecords[j] = depreciationPercentage;
			}
		}
		float deprecatedPrice = amount + downPayment;
		for (int i = 0; i <= duration; i++)
		{		
			deprecatedPrice = deprecatedPrice * (1.0 - depreciationRecords[i]);
			if(deprecatedPrice > amount){
				if(i > 1)
					cout << i << " months" << endl;
				else
					cout << i << " month" << endl;
				break;
			}
			amount -= downPayment;	
		}
	// }
	return 0;
}