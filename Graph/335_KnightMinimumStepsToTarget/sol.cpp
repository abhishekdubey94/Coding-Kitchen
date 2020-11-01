#include<bits/stdc++.h>
#define MAX 20
using namespace std;
struct cell{
    int x,y,dist;
    cell() {}
    cell(int x,int y,int dist): x(x), y(y), dist(dist){
    }
};
int stepsX[] = {2,2,1,1,-1,-1,-2,-2};
int stepsY[] = {1,-1,2,-2,2,-2,1,-1};

bool isInside(int x,int y,int n){
    if(x>=1 && x<=n && y>=1 && y<=n){
        return true;
    }
    return false;
}

int minimumStepsForKnight(int n,int posX,int posY,int tarX,int tarY){

    if(!isInside(posX,posY,n)){
        return -1;
    }
    queue<cell> q;
    cell o = cell(posX,posY,0);
    q.push(o);
    bool visited[n+1][n+1];

    for(int i=1;i<n+1;i++){
        for(int j=1;j<=n;j++){
            visited[i][j] = false;
        }
    }
    visited[posX][posY] = true;

    while(!q.empty()){
        cell c = q.front();
        q.pop();

        if(c.x==tarX && c.y==tarY){
            return c.dist;
        }

        for(int i=0;i<8;i++){
            if(isInside(c.x+stepsX[i],c.y+stepsY[i],n) && !visited[c.x+stepsX[i]][c.y+stepsY[i]]){
                cell newCell = cell(c.x+stepsX[i],c.y+stepsY[i],c.dist+1);
                visited[c.x+stepsX[i]][c.y+stepsY[i]] = true;
                q.push(newCell);
            }
        }
    }

    return -1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int posX,posY;
        int tarX,tarY;
        cin>>posX>>posY>>tarX>>tarY;
        cout<<minimumStepsForKnight(n,posX,posY,tarX,tarY)<<endl;
    }
    return 0;
}