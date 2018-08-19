#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> denom;
        for (int i = 0; i < n; ++i){
            int value;
            cin >> value;
            denom.push_back(value);
        }
        int sum = 1;
        int coins = denom.size() > 1 ? 2 : 1;
        for (int i = 1; i < denom.size() - 1; ++i){
            if (sum + denom[i] < denom[i + 1]){
                sum += denom[i];
                coins++;
            }
        }
        cout << coins << endl;
    }
    return 0;
}
