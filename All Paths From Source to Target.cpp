#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> paths;
    vector<int> path;
    void findPaths(vector<vector<int>> graph,vector<bool> vis,int cur,int n){
        if(cur==n-1){
            paths.push_back(path);
            return;
        }
        for(int v:graph[cur]){
            if(vis[v]) continue;
            path.push_back(v);
            vis[v] = true;
            findPaths(graph,vis,v,n);
            path.pop_back();
            vis[v] = !vis[v];
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int nodes = graph.size();
        vector<bool> vis(nodes,false);
        path.push_back(0);
        vis[0] = true;
        findPaths(graph,vis,0,nodes);
        return paths;
    }
};