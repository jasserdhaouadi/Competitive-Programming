// Problem link: https://leetcode.com/problems/find-if-path-exists-in-graph/description/
#include <vector>
#include <queue>
class Solution {
public:
    bool validPath(int n, std::vector<std::vector<int>>& edges, int source, int destination) {
        if(source == destination)
            return true;
        std::vector<std::vector<int>> adj(n);
        for(int i=0; i<(int)edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        std::vector<bool> vis(n, false);
        std::queue<int> q;
        vis[source] = true;
        q.push(source);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(const int& u : adj[cur]){
                if(!vis[u]){
                    if(u == destination)
                        return true;
                    vis[u] = true;
                    q.push(u);
                }
            }
        }
        return false;
    }
};