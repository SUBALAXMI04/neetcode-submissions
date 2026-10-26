class Solution {
public:
    int countSubstrings(string s){
        int n = s.size();
        vector<vector<bool>> dp(n + 1,vector<bool>(n + 1,false));
        for(int i = 0;i < n;i++) dp[i][i] = true;
        int ans = n;
        for(int len = 2;len <= n;len++){
            for(int i = 0;i + len <= n;i++){
                int j = i + len - 1;
                if(s[i] == s[j]){
                    dp[i][j] = (len == 2) ? true : dp[i + 1][j - 1];
                    if(dp[i][j]) ans++;
                }
            }
        }
        return ans;
    }
};
