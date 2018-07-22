#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    
    long long n;
    cin >> n;
    vector<long long> v;
    long long x;
    for(int i = 0 ; i < n - 1; i++) {
        cin >> x;
        v.push_back(x);
    }

    long long papersNeeded = 1;
    long double tapeUsed = 0;
    bool done = false;
    long double height  = pow(2.0, -3/4.0);
    long double width = pow(2.0, -5/4.0);

    for(long long i = 0; i < v.size(); i++) {   
        tapeUsed += papersNeeded * height;
        swap(width, height);
        width = width / 2;
        papersNeeded *= 2;
        papersNeeded -= v[i];
        if(papersNeeded <= 0) {
            done = true;
            break;
        }
    }

    if(done) {
        printf("%.9Lf\n", tapeUsed);
    }
    else {
        cout << "impossible" << endl;
    }

    return 0;

}