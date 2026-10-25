class Solution {
public:
    vector<pair<int,int>> D = {{0,-1},{-1,0},{0,1},{1,0}};
    void dfs(int r,int c,vector<vector<int>>& H,vector<vector<bool>>& vis){
        vis[r][c] = true;
        for(auto [dr,dc] : D){
            int R = r + dr,C = c + dc;
            if(R >= 0 && C >= 0 && R < H.size() && C < H[0].size() && !vis[R][C] && H[r][c] <= H[R][C]) dfs(R,C,H,vis);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& H){
        int m = H.size(),n = H[0].size();
        vector<vector<bool>> pac(m,vector<bool>(n,false)),atl(m,vector<bool>(n,false));
        for(int j = 0;j < n;j++){
            dfs(0,j,H,pac);
            dfs(m - 1,j,H,atl);
        }
        for(int i = 0;i < m;i++){
            dfs(i,0,H,pac);
            dfs(i,n - 1,H,atl);
        }
        vector<vector<int>> ans;
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++)
                if(pac[i][j] && atl[i][j]) ans.push_back({i,j});
        return ans;
    }
};
