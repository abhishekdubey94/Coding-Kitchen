#include<iostream>
using namespace std;

class Solution{
  public:
    int middle(int A, int B, int C){
        if(A>B){
            if(B>C){
                return B;
            }else{
                return C;
            }
        }else{
            if(A>C){
                return A;
            }else{
                return C;
            }
        }
    }
};