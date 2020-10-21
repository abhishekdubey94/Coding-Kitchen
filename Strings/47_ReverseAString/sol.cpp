#include<bits/stdc++.h>
using namespace std;
class Solution{
   
    public:
        void reverseString(vector<char>& s){
            int n = s.size();
            for(int i=0;i<n/2;i++){
                char temp = s[i];
                s[i] = s[n-1-i];
                s[n-1-i] = temp; 
            }
        }
};

//https://leetcode.com/problems/reverse-string/
int main(){
vector<char> v ;
v.push_back('h');
v.push_back('e');
v.push_back('l');
v.push_back('l');
v.push_back('o');

Solution s = Solution();
s.reverseString(v);
for(int i=0;i<v.size();i++){
    cout<<(char)v.at(i)<<" ";
}

}