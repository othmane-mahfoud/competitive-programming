#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    while (true) {
        cin >> n;
        if(n == 0)
            break;
        vector<int> v;
        int temp;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            if (temp != 0) {
                v.push_back(temp);
            }
        }
        if (v.size() == 0) {
            cout << 0 << endl;
        }
        else{
            for (int j = 0; j < v.size(); j++) {
                if (j != v.size() - 1) {
                    cout << v[j] << " ";
                }
                else
                    cout << v[j] << endl;
            }
        }
    }
}
