#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int min(int x, int y, int z){
    return min(min(x, y), z);
}

int editDistance(string word1, string word2){
    int i, j, l1, l2, m;
    l1 = word1.length();
    l2 = word2.length();
    vector< vector<int> > t(l1 + 1, vector<int>(l2 + 1));
    
    for (i = 0; i <= l1; i++)
        t[i][0] = i;
    for (i = 1; i <= l2; i++)
        t[0][i] = i;
    
    for (i = 1; i <= l1; i++){
        for (j = 1; j <= l2; j++){
            t[i][j] = min(t[i-1][j], //Delete
                          t[i][j-1] + 1, //Insert
                          t[i-1][j-1] + (word1[i-1] == word2[j-1] ? 0 : 1) //Copy or Replace
            );
        }
    }
    return t[l1][l2];
}

int main(){
    string str1 = "othmane";
    string str2 = "imane";
    
    cout << editDistance(str1, str2) << endl;
    
    return 0;
}
