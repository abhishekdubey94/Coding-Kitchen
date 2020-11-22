#include<bits/stdc++.h>
using namespace std;

void survival(int S,int N,int M){
    if(N<M || (S>6 && (7*M)>(6*N))){
        cout<<"No"<<endl;
    }else{
        int days = (M*S)/N;
        if((M*S)%N!=0) days++;
        cout<<"Yes "<<days<<endl;
    }
}

int main(){
    int S = 10, N = 16, M = 2; 
    survival(S, N, M);
    return 0;
}