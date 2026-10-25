class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times,int n,int k){
        vector<vector<pair<int,int>>> adj(n + 1);
        for(auto &e : times) adj[e[0]].push_back({e[1],e[2]});
        vector<int> dist(n + 1,1e9);
        dist[k] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({k,0});
        while(!pq.empty()){
            auto [node,time] = pq.top(); pq.pop();
            if(time > dist[node]) continue;
            for(auto [v,x] : adj[node]){
                if(dist[v] > dist[node] + x){
                    dist[v] = dist[node] + x;
                    pq.push({v,dist[v]});
                }
            } 
        }
        int ans = 0;
        for(int i = 1;i <= n;i++){
            if(dist[i] == 1e9) return -1;
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};
