#include<iostream>
using namespace std;

void print(int m,int n,int* arr){
int i=0,j=0;
int vstart = 0;
int vend = m-1;
int hstart = 0;
int hend = n-1;
int p=m;
while(m!=0 && n!=0){
    i=vstart;
    for(j=hstart;j<=hend;j++){
        cout<<*((arr+i*p) + j)<<" ";
    }
    j--;
    m--;
    vstart++;
    for(i=vstart;i<=vend;i++){
         cout<<*((arr+i*p) + j)<<" ";
    }
    i--;
    n--;
    hend--;
    for(j=hend;j>=hstart;j--){
        cout<<*((arr+i*p) + j)<<" ";
    }
    j++;
    m--;
    vend--;
    for(i=vend;i>=vstart;i--){
         cout<<*((arr+i*p) + j)<<" ";
    }
    i++;
    n--;
    hstart++;
}
}

int main(){
    int t ;
    cin>>t;
    while(t--){
        int n,m;
        cin>>m>>n;
        int a[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }

        print(m,n,(int*)a);
    }
    return 0;
}