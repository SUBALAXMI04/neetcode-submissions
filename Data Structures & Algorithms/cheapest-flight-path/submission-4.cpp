class Solution {
public:
    int findCheapestPrice(int n,vector<vector<int>>& flights,int src,int dst, int k){
        vector<int> dist(n,1e9);
        dist[src] = 0;
        for(int i = 0;i <= k;i++){
            vector<int> temp = dist;
            for(auto& e : flights){
                int u = e[0],v = e[1],x = e[2];
                if(dist[u] != 1e9 && temp[v] > dist[u] + x) temp[v] = dist[u] + x;
            }
            dist = temp;
        }
        return (dist[dst] >= 1e9) ? -1 : dist[dst];


        
    //   vector<int> dist(n,1e9);
    //   vector<vector<pair<int,int>>> adj(n);
    //   for(auto& e : flights) adj[e[0]].push_back({e[1],e[2]});
    //   queue<tuple<int,int,int>> Q;
    //   Q.push({0,0,src});
    //   dist[src] = 0;
    //   while(!Q.empty()){
    //     auto [stop,x,node] = Q.front(); Q.pop();
    //     if(stop > k) continue;
    //     for(auto [v,w] : adj[node]){
    //         if(dist[v] > x + w && stop <= k){
    //             dist[v] = x + w;
    //             Q.push({stop + 1,dist[v],v});
    //         }
    //     }
    //   }
    //   return (dist[dst] >= 1e9) ? -1 : dist[dst];
    }
};
