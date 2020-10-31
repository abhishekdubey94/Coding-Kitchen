#include<bits/stdc++.h>
#define V 9
using namespace std;

int findMinimum(int dist[] ,bool *spt){
    int minVal = INT_MAX;
    int minIndex;
    for(int i=0;i<V;i++){
        if(!spt[i] && minVal>=dist[i]){
            minVal = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// A utility function to print the constructed distance array 
void printSolution(int dist[]) 
{ 
    printf("Vertex \t\t Distance from Source\n"); 
    for (int i = 0; i < V; i++) 
        printf("%d \t\t %d\n", i, dist[i]); 
}

void dijkstra(int graph[V][V],int src){
    //array storing value of confirmed shortest distance
    bool spt[V];
    //memset(spt,false,sizeof(spt));

    //array to store the shortest distance
    int dist[V];
    //memset(dist,INT_MAX,sizeof(dist));

    for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX, spt[i] = false;
    //set the source and set the distance as 0
    dist[src] = 0;

    //for each vertices
    for(int i=0;i<V-1;i++){
        int u = findMinimum(dist,spt);
        spt[u] = true;
        
        for(int j=0;j<V;j++){
            if(!spt[j] && graph[u][j] && dist[j]>dist[u]+graph[u][j] && dist[u]!=INT_MAX ){
                dist[j] = dist[u]+graph[u][j];
            }
        }

    }


//print
printSolution(dist);
}
int main() 
{ 
    /* Let us create the example graph discussed above */
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
  
    dijkstra(graph, 0); 
  
    return 0; 
}