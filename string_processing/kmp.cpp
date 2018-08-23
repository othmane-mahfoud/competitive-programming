#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>


using namespace std;

template <class T> int size(T &x) { return x.size(); }

// assert or gtfo

int* compute_pi(const string &t) {
    
    int m = t.size();
    int *pi = new int[m + 1];
    if (0 <= m) pi[0] = 0;
    if (1 <= m) pi[1] = 0;
    for (int i = 2; i <= m; i++) {
        for (int j = pi[i - 1]; ; j = pi[j]) {
            if (t[j] == t[i - 1]) {
                pi[i] = j + 1;
                break;
            }
            if (j == 0) {
                pi[i] = 0;
                break;
            }
        }
    }
    
    return pi;
}

int string_match(const string &s, const string &t) {
    
    int n = s.size(),
    m = t.size();
    
    int *pi = compute_pi(t);
    
    for (int i = 0, j = 0; i < n; ) {
        if (s[i] == t[j]) {
            i++; j++;
            if (j == m) {
                return i - m;
            }
        }
        else if (j > 0) j = pi[j];
        else i++;
    }
    
    delete[] pi;
    return -1;
}

int main()
{
    string s = "othmane";
    string t = "man";
    
    printf("%d\n", string_match(s, t));
    
    return 0;
}


