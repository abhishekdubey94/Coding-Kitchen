#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int a[n],b[m];
        set<int> s;
        int p;
        for(int i=0;i<n;i++){
            cin>>p;
            a[i] = p;
            s.insert(p);
        }
        for(int i=0;i<m;i++){
            cin>>p;
            b[i] = p;
            s.insert(p);
        }
        cout<<s.size()<<endl;
    }
    return 0;
}