#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    string output = "";
    output += s[0];
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == '-') {
            output += s[i+1];
        }
    }
    cout << output;
    return 0;
}
