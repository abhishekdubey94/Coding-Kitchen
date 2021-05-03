#include<bits/stdc++.h>
using namespace std;


bool getAllPossibleWordBreaks(int N,string dict[],string s,int start,int pos,vector<string>* v){
    if(pos==N){
        return true;
    }

    for(int i=start;i<pos;i++){
        if(find(dict,dict+N,s.substr(start,pos))){
            
        }
    }
}
int main(){

    int t;
    cin>>t;

    while(t--){
        int N;
        string s;
        string dict[N];
        cin>>N;
        for(int i=0;i<N;i++){
            cin>>dict[i];
        }
        cin>>s;
        vector<string> v;
        getAllPossibleWordBreaks(N,dict,s,0,0,&v);

        for(int i=0;i<v.size();i++){
            cout<<v[i];
        }
    }

    return 0;

}