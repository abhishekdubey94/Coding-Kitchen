#include<bits/stdc++.h>
using namespace std;
#define N 8

int board[N][N];
bool isSafe(int x,int y){
    if(x>=N || y>=N || x<0 || y<0){
        return false;
    }
    for(int j=0;j<N;j++){
        if(j==y) continue;
        if(board[x][j]==1){
            return false;
        }
    }

    for(int i=0;i<N;i++){
        if(i==x) continue;
        if(board[i][y]==1){
            return false;
        }
    }

    for(int i=x-1,j=y-1;i>=0 && j>=0 ; i--,j-- ){
        if(board[i][j]==1){
            return false;
        }
    }
    for(int i=x+1,j=y-1;i<N && j>=0 ; i++,j-- ){
        if(board[i][j]==1){
            return false;
        }
    }

    return true;
}
void print(int b[][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
}
bool placeNQueens(int col){
    if(col==N){
        print(board);
        return true;
    }
    bool res = false;
    for(int row=0;row<N;row++){
        board[row][col] = 1;

        if(isSafe(row,col)){
            res = placeNQueens(col+1);
        }

        board[row][col] = 0;
    }
return res;
}
int main(){
    memset(board,0,sizeof(board));
    placeNQueens(0);
    return 0;
}