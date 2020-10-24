#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int isPalindrome(string s){
            int n = s.length();
            for(int i=0;i<n/2;i++){
                if(s[i]!=s[n-1-i]){
                    return 0;
                }
            }
            return 1;
        }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.isPalindrome(s)<<"\n";
    }
    return 0;
}