#include <bits/stdc++.h>

using namespace std;

int main(){
    int a;
    int b;
    cin >> a >> b;
    a = (a%10)*100 + ((a%100)-(a%10)) + ((a%1000)-(a%100))/100;
    b = (b%10)*100 + ((b%100)-(b%10)) + ((b%1000)-(b%100))/100;
    cout << max(a, b);
    return 0;
}
