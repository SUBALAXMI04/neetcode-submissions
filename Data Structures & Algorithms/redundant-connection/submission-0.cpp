class Solution {
public:
    vector<int> rank,parent;
    int findPar(int x){
        if(x == parent[x]) return x;
        return parent[x] = findPar(parent[x]);
    }
    bool unite(int a,int b){
        a = findPar(a);
        b = findPar(b);
        if(a == b) return false;
        if(rank[a] == rank[b]) rank[a]++;
        else if(rank[a] < rank[b]) swap(a,b);
        parent[b] = a;
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges){
        int n = edges.size();
        rank.resize(n + 1,0);
        parent.resize(n + 1);
        for(int i = 0;i <= n;i++) parent[i] = i;
        for(auto &e : edges){
            if(!unite(e[0],e[1])) return e;
        }
        return {};
    }
};
