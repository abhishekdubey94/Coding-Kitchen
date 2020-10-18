#include <bits/stdc++.h>
using namespace std;


void exch(int arr[],int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void randomise(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int ind = (rand()%(n-i))+i;
        exch(arr,ind,i);
    }    
}

int quickSelect(int arr[],int n, int k){

    int l = 0;
    int r = n-1;

    while(l<=r){
        int pivot = arr[r];
        int i=l;
        int j=l;
        while(j<=r-1){
            if(arr[j]<pivot){
                exch(arr,j,i);
                i++;
            }
            j++;
        }
        exch(arr,i,r);
        if(i==k-1){
            return arr[k-1];
        }
        else if(i<k-1){
            l = i+1;
        }else{
            r = i-1;
        }
    }

 for(int i=0;i<n;i++){
     cout<<arr[i]<<" ";
 }
    return arr[k-1];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cin>>k;
        randomise(a,n);
        cout<<quickSelect(a,n,k)<<endl;
    }
    
    return 0;
}