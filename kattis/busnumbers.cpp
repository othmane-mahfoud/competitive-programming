#include<iostream>
#include<algorithm>

using namespace std;

int main (){
    int N;
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    sort(arr,arr+N);
    int i = 0;
    while(i<N){
        int counter = 0;
        int start = i;
        while(arr[i]+1==arr[i+1]){
            counter++;
            i++;
        }
        if(counter>1){
            cout<<arr[start]<<"-"<<arr[start+counter]<<" ";
            i = start+counter+1;
        }
        else{
            cout<<arr[start]<<" ";
            i = start+1;
        }
    }
    return 0;
}