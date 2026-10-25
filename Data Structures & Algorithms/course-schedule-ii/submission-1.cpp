class Solution {
public:
    vector<int> findOrder(int num,vector<vector<int>>& P){
        vector<vector<int>> adj(num);
        vector<int> indegree(num,0),ans;
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
            ans.push_back(node);
            for(int v : adj[node]){
                indegree[v]--;
                if(indegree[v] == 0) Q.push(v);
            }
        }
        if(ans.size() < num) return {};
        return ans;
    }
};
