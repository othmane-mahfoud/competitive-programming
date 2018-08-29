#include <bits/stdc++.h>

using namespace std;

vector<int> findDivisors(int n){
    vector<int> divisors;
    for (int i=2; i<=sqrt(n); i++){
        if (n%i == 0){
            if (n/i == i)
                divisors.push_back(i);
            else{
                divisors.push_back(i);
                divisors.push_back(n/i);
            }
        }
    }
    return divisors;
}

int main(){
    int n;
    while (true) {
        cin >> n;
        if (n == 0)
            break;
        vector<int> divisors = findDivisors(n);
        int max_pow = 1;
        for (int i = 0; i < divisors.size(); i++) {
            int j = 1;
            while (pow(i, j) <= n) {
                if(pow(i, j) == n && j > max_pow)
                    max_pow = j;
                j++;
            }
        }
        cout << max_pow << endl;
    }
    return 0;
}
