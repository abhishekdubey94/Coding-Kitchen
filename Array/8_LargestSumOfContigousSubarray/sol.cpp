#include <iostream>
#include<climits>
using namespace std;

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
        
        int max=INT_MIN;
        int loc=0;
        
        for(int i=0;i<n;i++){
            loc+=arr[i];
            if(loc>max){
                max = loc;
            }
            if(loc<0){
                loc = 0;
            }
        }
        
        cout<<max<<endl;
    }
}