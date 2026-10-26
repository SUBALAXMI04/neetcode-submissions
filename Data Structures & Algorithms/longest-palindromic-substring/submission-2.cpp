class Solution {
public:
    string longestPalindrome(string s){
        int n = s.size(),maxi = 1,stIdx = 0;
        vector<vector<bool>> dp(n + 1,vector<bool>(n + 1,false));
        for(int i = 0;i < n;i++) dp[i][i] = true;
        for(int len = 2;len <= n;len++){
            for(int i = 0;i + len <= n;i++){
                int j = len + i - 1;
                if(s[i] == s[j]){
                    dp[i][j] = (len == 2) ? true : dp[i + 1][j - 1];
                    if(dp[i][j] && maxi < len){
                        maxi = len;
                        stIdx = i;
                    }
                }
            }
        }
        return s.substr(stIdx,maxi);
    }
};
