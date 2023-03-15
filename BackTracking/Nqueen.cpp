#include "bits/stdc++.h"
using namespace std;
bool isSafe(int row , int col , vector<vector<int>>&board,int n){
    int x = row , y = col;
    //same row;
    while(y>=0){
        if(board[x][y] == 1)
            return false;
        y--;
    }
    //upper left diagonal;
    x = row , y =col;
    while(x>=0 && y>=0){
         if(board[x][y] == 1)
            return false;
        x--;
        y--;
    }
    //left lower diagonal;

    x = row , y = col;
    while(x<n && y>=0){
         if(board[x][y] == 1)
            return false;
        x++;
        y--;
    }
    return true;


}
void solve(int col , vector<vector<int>> &board, vector<vector<int>>&ans,vector<int>&pos,int n){
    if(col == n){
        ans.push_back(pos);
        return;
    }
    for(int row = 0;row<n;row++){
        if(isSafe(row,col,board,n)){
            pos.push_back(row+1);
            board[row][col] = 1;
            solve(col+1,board,ans,pos,n);
            board[row][col] = 0;
            pos.pop_back();
        }
    }
}
int main(){
    int n = 4;
    vector<vector<int>> ans;
    vector<vector<int>> board(n,vector<int>(n,0));
    vector<int> pos;
    solve(0,board,ans,pos,n);
    for (int i = 0; i < ans.size(); i++)
   {
       for (int j: ans[i])
       {
        cout<<j<<" ";
       }
       cout<<endl;
       
   }

return 0;
}