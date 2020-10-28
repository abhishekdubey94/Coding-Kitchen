#include<bits/stdc++.h>
using namespace std;
struct job{
    int id;
    int deadline;
    int profit;
};

bool jobSorter(job a,job b){
    if(a.deadline == b.deadline) return a.profit < b.profit;
    return a.deadline < b.deadline;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<job> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i].id>>v[i].deadline>>v[i].profit;
        }

        sort(v.begin(),v.end(),jobSorter);

        // for(int i=0;i<n;i++){
        //     cout<<"\n"<<v[i].id<<" "<<v[i].deadline<<" "<<v[i].profit<<"\n";
        // }
        int lastDeadline = v[0].deadline;
        int lastProfit = v[0].profit;
        int totalProfit = v[0].profit;
        int count = 1;

        for(int i=1;i<n;i++){
            if(lastDeadline==v[i].deadline){
                totalProfit = totalProfit-lastProfit+v[i].profit;
                lastProfit = v[i].profit;
            }else{
                totalProfit +=v[i].profit;
                lastDeadline = v[i].deadline;
                count++;
            }
        }

        cout<<count<<" "<<totalProfit;
    }
    return 0;
}