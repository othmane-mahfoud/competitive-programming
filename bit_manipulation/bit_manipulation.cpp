#include <bits/stdc++.h>

using namespace std;

int main(){
    int num = 0;
    int pos;
    
    // set bit at nth position
    pos = 1;
    num |= (1 << pos);
    cout << num << endl;
    
    // clear bit at nth position
    pos = 1;
    num &= (~(1 << pos));
    cout << num << endl;
    
    // toggle a bit
    pos = 0;
    num ^= (1 << pos);
    cout << num << endl;
    
    // check if bit is set or unset
    bool bit;
    pos = 0;
    bit = num & (1 << pos);
    cout << bit << endl;
    pos = 1;
    bit = num & (1 << pos);
    cout << bit << endl;
    
    // Stripping off the lowest set bit
    num = num & (num-1);
    cout << num << endl;
    
    // set all bits in a range
    int l = 1, r = 2;
    int range = (((1 << (l - 1)) - 1) ^ ((1 << (r)) - 1));
    num = num | range;
    
    return 0;
}
