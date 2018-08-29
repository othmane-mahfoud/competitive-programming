#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
    string command;
    map<string, int> m;
    map<int, string> m2;
    while (getline(cin, command)) {
        istringstream is(command);
        string s;
        is >> s;
        if (s.compare("def") == 0) {
            string word;
            int val;
            is >> word;
            is >> val;
            m[word] = val;
            m2[val] = word;
        }
        else if (s.compare("calc") == 0){
            bool flag = false;
            string output = "";
            string str;
            is >> str;
            output += str + " ";
            ll sum = m[str];
            while(true){
                string op;
                is >> op;
                output += op + " ";
                if(op.compare("=") == 0)
                    break;
                else if (op.compare("+") == 0){
                    is >> str;
                    output += str + " ";
                    if (m.find(str) == m.end())
                        flag = true;
                    else
                        sum += m[str];
                }
                else if (op.compare("-") == 0){
                    is >> str;
                    output += str + " ";
                    if (m.find(str) == m.end())
                        flag = true;
                    else
                        sum -= m[str];
                }
            }
            if (m2.find(sum) == m2.end() || flag)
                cout << output << "unknown" << endl;
            else
                cout << output << m2[sum] << endl;
        }
        else{
            m.clear();
            m2.clear();
        }
    }
    return 0;
}
