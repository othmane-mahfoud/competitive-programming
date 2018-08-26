#include <bits/stdc++.h>

using namespace std;

void findLIS(int arr[], int n)
{
    // LIS[i] stores the longest increasing subsequence of subarray
    // arr[0..i] that ends with arr[i]
    vector<int> LIS[n];
    
    // LIS[0] denotes longest increasing subsequence ending with arr[0]
    LIS[0].push_back(arr[0]);
    // start from second element in the array
    for (int i = 1; i < n; i++)
    {
        // do for each element in subarray arr[0..i-1]
        for (int j = 0; j < i; j++)
        {
            // find longest increasing subsequence that ends with arr[j]
            // where arr[j] is less than the current element arr[i]
            
            if (arr[j] < arr[i] && LIS[j].size() > LIS[i].size())
                LIS[i] = LIS[j];
        }
        
        // include arr[i] in LIS[i]
        LIS[i].push_back(arr[i]);
    }
    
    // j will contain index of LIS
    int j;
    for (int i = 0; i < n; i++)
        if (LIS[j].size() <= LIS[i].size())
            j = i;
    
    // print length of lis
    
    int lis_len = LIS[j].size();
    cout << lis_len << endl;
    cout << "-" << endl;
   
    // print LIS
    for (int i = 0; i < LIS[j].size(); i++)
        cout << LIS[j][i] << endl;
}

int main(){
    freopen("o.txt", "w", stdout);
    int arr[100000];
    int i = 0;
    int n;
    while (cin >> n) {
        arr[i] = n;
        i++;
    }
    cout << "here" << endl;
    findLIS(arr, i);
    return 0;
}

