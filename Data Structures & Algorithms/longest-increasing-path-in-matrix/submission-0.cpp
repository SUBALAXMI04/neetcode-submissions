class Solution {
public:
    vector<pair<int,int>> D = {{0,-1},{-1,0},{0,1},{1,0}};
    int lip_rec(int row,int col,vector<vector<int>>& mat,vector<vector<int>>& dp){
        int m = mat.size(),n = mat[0].size(),ans = 1;
        if(dp[row][col] != -1) return dp[row][col];
        for(auto [dr,dc] : D){
            int R = row + dr,C = col + dc;
            if(R >= 0 && C >= 0 && R < m && C < n && mat[row][col] < mat[R][C])
                ans = max(ans,1 + lip_rec(R,C,mat,dp));
        }
        return dp[row][col] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& mat){
        int ans = 1,m = mat.size(),n = mat[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++)
                ans = max(ans,lip_rec(i,j,mat,dp));
        return ans;
    }
};
