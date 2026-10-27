class Solution {
public:
    int path_rec(int row,int col){
        if(row < 0 || col < 0) return 0;
        if(row == 0 && col == 0) return 1;
        int right = path_rec(row,col - 1);
        int down = path_rec(row - 1,col);
        return down + right;
    }
    int path_tab(int m,int n){
        vector<vector<int>> dp(m + 1,vector<int>(n + 1,0));
        dp[1][1] = 1;
        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= n;j++){
                if(i == 1 && j == 1) continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
    int path_space(int m,int n){
        vector<int> curr(n + 1,0);
        curr[1] = 1;
        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= n;j++){
                if(i == 1 && j == 1) continue;
                curr[j] += curr[j - 1];
            }
        }
        return curr[n];
    }
    int uniquePaths(int m,int n){
        // return path_rec(m - 1,n - 1);
        // return path_tab(m,n);
        return path_space(m,n);
    }
};
