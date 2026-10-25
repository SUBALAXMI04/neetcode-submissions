class Solution {
public:
    void dfs(int u,vector<vector<int>>& adj,vector<bool>& visited){
        visited[u] = true;
        for(int v : adj[u]){
            if(!visited[v]) dfs(v,adj,visited);
        }
    }
    int countComponents(int n,vector<vector<int>>& edges){
        int cnt = 0;
        vector<bool> visited(n,false);
        vector<vector<int>> adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for(int i = 0;i < n;i++){
            if(!visited[i]){
                cnt++;
                dfs(i,adj,visited);
            }
        }
        return cnt;
    }
};
