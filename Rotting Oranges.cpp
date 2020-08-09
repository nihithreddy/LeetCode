#include<bits/stdc++.h>
using namespace std;
struct Pair{
    int x,y,cnt;
    Pair(int x,int y,int c){
       this->x = x;
       this->y = y;
       this->cnt = c;
    }
};
const int dx[]={-1,1,0,0};
const int dy[]={0,0,1,-1};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        if(rows==0||grid.empty()){
            return 0;
        }
        int cols  = grid[0].size();
        vector<vector<bool>> vis(rows,vector<bool>(cols,false));
        map<pair<int,int>,bool> rotten;
        queue<Pair> q;
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                if(grid[row][col]==2){
                    q.push(Pair(row,col,0));
                    //vis[row][col]=1;
                }
                if(grid[row][col]==1){
                    rotten[{row,col}]=1;
                }
            }
        }
        int ans = 0;
        while(!q.empty()){
            Pair p = q.front();
            q.pop();
            ans=max(ans,p.cnt);
            for(int k=0;k<4;k++){
                int x1 = p.x+dx[k];
                int y1 = p.y+dy[k];
                if(x1>=0&&x1<rows&&y1>=0&&y1<cols&&grid[x1][y1]==1&&!vis[x1][y1]){
                    grid[x1][y1]=2;
                    vis[x1][y1]=1;
                    rotten.erase({x1,y1});
                    q.push(Pair(x1,y1,p.cnt+1));
                }
            }
        }
        return (rotten.size()==0)?ans:-1;
    }
};