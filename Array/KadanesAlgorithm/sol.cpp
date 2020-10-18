#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        int max_so_far = a[0];
        int local_max = a[0];
        for(int i=1;i<n;i++){
            local_max +=a[i];
            if(local_max>max_so_far){
                max_so_far = local_max;
            }
        }

        cout<<max_so_far<<endl;

    }
}