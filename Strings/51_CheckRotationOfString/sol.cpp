#include<bits/stdc++.h>
using namespace std;

bool areRotations(string s1, string s2){
    if(s1.length()!=s2.length()){
        return false;
    }
    string temp = s1+s1;
    return (temp.find(s2)!=string::npos);
}
int main(){
string str1 = "AACD", str2 = "ABDA"; 
   if (areRotations(str1, str2)) 
     printf("Strings are rotations of each other"); 
   else
      printf("Strings are not rotations of each other"); 
   return 0;
}