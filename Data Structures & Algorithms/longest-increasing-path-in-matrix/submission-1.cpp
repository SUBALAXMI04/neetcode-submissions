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
    int lip_tab(vector<vector<int>>& mat){
        int m = mat.size(),n = mat[0].size(),ans = 1;
        vector<vector<int>> dp(m,vector<int>(n,1));
        vector<tuple<int,int,int>> cells;
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++)
                cells.push_back({mat[i][j],i,j});
        sort(cells.begin(),cells.end());
        for(auto [val,i,j] : cells){
            for(auto [di,dj] : D){
                int I = i + di,J = j + dj;
                if(I >= 0 && J >= 0 && I < m && J < n && mat[i][j] > mat[I][J])
                    dp[i][j] = max(dp[i][j],1 + dp[I][J]);
            }
            ans = max(ans,dp[i][j]);
        }
        return ans;
    }
    int longestIncreasingPath(vector<vector<int>>& mat){
        int ans = 1,m = mat.size(),n = mat[0].size();
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // for(int i = 0;i < m;i++)
        //     for(int j = 0;j < n;j++)
        //         ans = max(ans,lip_rec(i,j,mat,dp));
        // return ans;
        return lip_tab(mat);
    }
};
