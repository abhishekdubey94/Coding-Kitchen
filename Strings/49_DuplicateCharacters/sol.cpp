#include<bits/stdc++.h>
using namespace std;

void printDuplicateChar(string tc){
    map<char,int> m;

    for(int i=0;i<tc.length();i++){
        if(tc[i]==' '){
            continue;
        }
        m[tc[i]]++;        
    }
    map<char, int>::iterator itr;
    for(itr=m.begin();itr!=m.end();itr++){
        if(itr->second>1){
            cout<<itr->first<<", count = "<<itr->second<<endl;
        }
    }
}

int main(){
    string tc;
    getline(cin,tc);

    printDuplicateChar(tc);

    return 0;
}