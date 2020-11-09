#include<iostream>
using namespace std;

int maximumProduct(int arr[],int n){
    int r = arr[0];

    for(int i=1,imax=r,imin=r;i<n;i++){
        if(arr[i]<0){
            swap(imax,imin);
        }

        imax = max(arr[i],arr[i]*imax);
        imin = min(arr[i],arr[i]*imin);

        r = max(imax,r);
    }
    return r;
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

        cout<<maximumProduct(arr,n)<<endl;
    }
}
