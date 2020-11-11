#include<bits/stdc++.h>
using namespace std;
#define MAX 8

int board[MAX][MAX] = {-5};
int moveX[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int moveY[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

bool isSafe(int x,int y){
    if(x>=0 && x<MAX && y>=0 && y<MAX && board[x][y]==-1){
        return true;
    }
    return false;
}

int knightsTour(int x,int y,int count){
    if (count == MAX*MAX)
        return 1;
    for(int i=0;i<MAX;i++){
        if(isSafe(x+moveX[i],y+moveY[i])){
            board[x+moveX[i]][y+moveY[i]] = count;
            if(knightsTour(x+moveX[i],y+moveY[i],count+1)==1){
                return 1;
            }else{
                board[x+moveX[i]][y+moveY[i]] = -1;
            }
        }
            
    }
    return 0;
}

void printBoard(){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    memset(board,-1,sizeof(board));
    board[0][0] = 0;
    knightsTour(0,0,1);
    printBoard();
    return 0;
}