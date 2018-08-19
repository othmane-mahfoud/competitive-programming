#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int c = 1; c <= t; c++){
        int n;
        cin >> n;
        vector<char> seq(n+2, '#');
        for (int i = 0; i < n; i ++) {
            cin >> seq[i];
        }
        int scare_count = 0;
        for (int i = 0; i < n; i ++) {
            if (seq[i] == '.') {
                seq[i] = seq[i+1] = seq[i+2] = '#';
                scare_count++;
            }
        }
        cout << "Case " << c << ": " << scare_count << endl;
    }
}
