#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int check_string(string s, int k){
    for (int i = 0; i < k; ++i){
        char c = s[i];
        for (int j = i + k; j < s.length(); j += k)
            if (s[j] != c)
                return 0;
    }
    return 1;
}

int main(){
    int t;
    cin >> t;
    string s;
    for(int i = 0; i < t; i++){
        cin >> s;
        int flag = 0;
        for (int k = 1; k < s.length(); k++){
            if (s.length() % k == 0){
                if (check_string(s, k)){
                    cout << k << '\n';
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 0)
            cout << s.length() << '\n';
    }
}
