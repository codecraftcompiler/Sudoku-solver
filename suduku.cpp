#include<iostream>
using namespace std;
bool safe(int board[9][9],int i,int j,int n,int num){
    for(int k=0;k<n;k++){
        if(board[i][k]==num){
            return false;
        }
    }
    for(int k=0;k<n;k++){
        if(board[k][j]==num){
            return false;
        }
    }
    int x=(i/3)*3,y=(j/3)*3;
    for(int l=x;l<x+3;l++){    
        for(int k=y;k<y+3;k++){
            if(board[l][k]==num){
                return false;
            }
        }
    }
    return true;
}
bool abc(int board[9][9],int i,int j,int n){
    if(i==n){
        for(int l=0;l<n;l++){
            for(int k=0;k<n;k++){
                cout<<board[l][k]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    if(j==n){
        return abc(board,i+1,0,n);
    }
    if(board[i][j]!=0){
        return abc(board,i,j+1,n);
    }
    for(int k=1;k<=n;k++){
        bool yes=safe(board,i,j,n,k);
        if(yes==true){
            board[i][j]=k;
            bool next=abc(board,i,j+1,n);
            if(next==true){
               return true;
            }
              board[i][j]=0;
        }
    }
    return false;
}
int main(){
    int board[9][9] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    abc(board,0,0,9);
    return 0;
}