#include<bits/stdc++.h>
using namespace std;

struct ele{
    int start;
    int end;
    int pos;
};

bool sortFun(ele a,ele b){
    if(a.end == b.end) return a.start<b.start;
    return a.end < b.end;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ele> v(n);
        for(int i=0;i<n;i++){
            int p;
            cin>>p;
            v[i].start = p;
            v[i].pos = i;
        }
        for(int i=0;i<n;i++){
            cin>>v[i].end ;
        }

        sort(v.begin(),v.end(),sortFun);

        int st = -1;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(st<v[i].start){
                ans.push_back(v[i].pos+1);
                st = v[i].end;
            }
        }
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}