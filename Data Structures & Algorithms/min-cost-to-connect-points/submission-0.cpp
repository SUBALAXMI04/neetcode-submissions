class Solution {
public:
    vector<int> parent,size;
    int findPar(int x){
        if(parent[x] == x) return x;
        return parent[x] = findPar(parent[x]);
    }
    bool unite(int a,int b){
        a = findPar(a);
        b = findPar(b);
        if(a == b) return false;
        if(size[a] < size[b]) swap(a,b);
        size[a] += size[b];
        parent[b] = a;
        return true;
    }
    int minCostConnectPoints(vector<vector<int>>& P){
        vector<array<int,3>> edges;
        int n = P.size(),ans = 0;
        size.resize(n + 1,1);
        parent.resize(n + 1);
        for(int i = 0;i <= n;i++) parent[i] = i;
        for(int i = 0;i < n;i++){
            for(int j = i + 1;j < n;j++){
                int dist = abs(P[i][0] - P[j][0]) + abs(P[i][1] - P[j][1]);
                edges.push_back({dist,i,j});
            }
        }
        sort(edges.begin(),edges.end());
        for(auto& [dist,u,v] : edges){
            if(unite(u,v)) ans += dist;
        }
        return ans;
    }
};
