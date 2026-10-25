class Solution {
public:
    bool dfs(int node,int par,vector<vector<int>>& adj,vector<bool>& visited){
        visited[node] = true;
        for(int v : adj[node]){
            if(!visited[v]){
                if(dfs(v,node,adj,visited)) return true;
            }
            else if(v != par) return true;
        }
        return false;
    }
    bool validTree(int n,vector<vector<int>>& edges){
        if(edges.size() != n - 1) return false;
        vector<bool> visited(n,false);
        vector<vector<int>> adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for(int i = 0;i < n;i++){
            if(!visited[i]){
                if(dfs(i,-1,adj,visited)) return false;
            }
        }
        return true;
    }
};
