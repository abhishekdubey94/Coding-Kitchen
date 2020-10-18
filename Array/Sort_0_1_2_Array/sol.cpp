#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        int z=0,tw=0,o=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            
            if(a[i]==0){
                z++;
            }else if(a[i]==1){
                o++;
            }
            else{
                tw++;
            }
        }

        int i = 0;
        while(z--){
            a[i] = 0;
            i++;
        }
        while(o--){
            a[i]=1;
            i++;
        }
        while(tw--){
            a[i]=2;
            i++;
        }

        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
    }
}

//https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s/0