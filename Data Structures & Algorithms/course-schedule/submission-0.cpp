class Solution {
public:
    bool canFinish(int num,vector<vector<int>>& P){
        vector<vector<int>> adj(num);
        vector<int> indegree(num,0);
        for(auto &e : P){
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }
        queue<int> Q;
        for(int i = 0;i < num;i++){
            if(indegree[i] == 0) Q.push(i);
        }
        while(!Q.empty()){
            auto node = Q.front(); Q.pop();
            for(auto v : adj[node]){
                indegree[v]--;
                if(indegree[v] == 0) Q.push(v);
            }
        }
        for(int i : indegree){
            if(i != 0) return false; 
        }
        return true;
    }
};
