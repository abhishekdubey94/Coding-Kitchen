#include<bits/stdc++.h>
using namespace std;
void rotate(int arr[],int n){
    int temp = arr[n-1];

    for(int i=n-2;i>=0;i--){
        arr[i+1] = arr[i];
    }
    arr[0] = temp;

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        rotate(arr,n);
    }

    return 0;
}