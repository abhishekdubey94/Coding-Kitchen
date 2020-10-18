#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,x;
        cin>>n>>x;
        int a[n];
        int f = -1,s=-1;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(f==-1 && a[i]==x){
                f = i;
            }
            if(f!=-1 && a[i]==x){
                s = i;
            }

        }
        if(f!=-1){
            cout<<f<<" "<<s<<endl;
        }else{
            cout<<-1<<endl;
        }
        
    }
    return 0;
}