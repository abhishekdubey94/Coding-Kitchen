#include<bits/stdc++.h>
using namespace std;
bool checkValidShuffle(string s1,string s2,string result){
    if(s1.length()+ s2.length()!=result.length()){
        return false;
    }
    int i=0,j=0,k=0;
    while(k!=result.length()){
        if(i<s1.length() && s1[i]==result[k]){
            i++;
        }else if(j<s2.length() && s2[j]==result[k]){
            j++;
        }else{
            return false;
        }
        k++;
    }
    return true;
}
int main(){
    string s1,s2;
    s1 = "XY";
    s2 = "12";
    string results[] = {"1XY2","2YX1"};

    for(string result : results){
        if(checkValidShuffle(s1,s2,result)){
            cout<<"It is a valid shuffle"<<endl;
        }else{
            cout<<"Not a valid shuffle"<<endl;
        }
    }
}