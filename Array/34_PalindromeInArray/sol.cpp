#include<bits/stdc++.h>
using namespace std;

int main(){

    return 0;
}

int PalinArray(int a[], int n)
{  
    for(int i=0;i<n;i++){
        int t = a[i];
        
        string s = to_string(t);
        int k = s.size();
        for(int p=0;p<s.size()/2;p++){
            if(s[p]!=s[k-p-1]){
                return 0;
            }
        }
    }
    
    return 1;
}