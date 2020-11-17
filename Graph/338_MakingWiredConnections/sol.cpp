#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()< n-1) return -1;  //at least n-1 connection required to connect n
        
        int parent[n];
        int size[n];
        
        for(int i=0;i<n;i++){
            parent[i] = i;
            size[i] = 1;
        }
        
        int component = n;
        for(vector<int> p : connections){
            int p1 = findParent(parent,p[0]);
            int p2 = findParent(parent,p[1]);
            
            if(p1!=p2){
                if(p1>p2){
                    size[p1]+=size[p2];
                    parent[p2] = parent[p1];
                }else{
                    size[p2]+=size[p1];
                    parent[p1] = parent[p2];
                }
                component--;
            }
        }
        
        return component-1;
    }
    
    int findParent(int parent[], int p){
        if(parent[p]==p){
            return p;
        }
        return findParent(parent,parent[p]);
    }
};