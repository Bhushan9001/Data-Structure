#include "bits/stdc++.h"
using namespace std;
 bool safe(int x , int y ,vector<vector<bool>> &vis,vector<vector<int>> &m,int n){
        if((x>=0 && x<n)&&(y>=0&&y<n)&&vis[x][y]==0 && m[x][y]==1) return true;
        else return false;
    }

void solve(int x , int y , vector<vector<int>> &m, int n , vector<string> &ans ,vector<vector<bool>> &vis, string path){
        
        if(x == n-1 && y == n-1){
            ans.push_back(path); 
            return;
        }
        vis[x][y] = 1;
        //Down
        if(safe(x+1,y,vis,m,n)) solve(x+1,y,m,n,ans,vis,path+'D');
        //Left
        if(safe(x,y-1,vis,m,n)) solve(x,y-1,m,n,ans,vis,path+'L');
        //Right  
        if(safe(x,y+1,vis,m,n)) solve(x,y+1,m,n,ans,vis,path+'R');
        //Up
        if(safe(x-1,y,vis,m,n)) solve(x-1,y,m,n,ans,vis,path+'U');
        
        
        vis[x][y] = 0;
        
        
    }

int main(){
   
    vector<vector<int>> m = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}};
         int n = 4;
    vector<string> ans;
    vector<vector<bool>> vis (n, vector<bool> (n,0));
    string path = "";
    solve(0,0,m,n,ans,vis,path);
        

    for (auto i : ans){
            cout<<i<<endl;
          }
          

return 0;
}