class Solution {
public:
    int lcs_rec(int i,int j,string s1,string s2){
        if(i == s1.size() || j == s2.size()) return 0;
        if(s1[i] == s2[j]) return 1 + lcs_rec(i + 1,j + 1,s1,s2);
        return max(lcs_rec(i + 1,j,s1,s2),lcs_rec(i,j + 1,s1,s2)); 
    }
    int lcs_tab(string s1,string s2){
        int n1 = s1.size(),n2 = s2.size();
        vector<vector<int>> dp(n1 + 1,vector<int>(n2 + 1,0));
        for(int i = n1 - 1;i >= 0;i--){
            for(int j = n2 - 1;j >= 0;j--){
                if(s1[i] == s2[j]) dp[i][j] = 1 + dp[i + 1][j + 1];
                else dp[i][j] = max(dp[i + 1][j],dp[i][j + 1]);
            }
        }
        return dp[0][0];
    }
    int lcs_space(string s1,string s2){
        int n1 = s1.size(),n2 = s2.size();
        vector<int> ahead(n2 + 1,0),curr(n2 + 1,0);
        for(int i = n1 - 1;i >= 0;i--){
            for(int j = n2 - 1;j >= 0;j--){
                if(s1[i] == s2[j]) curr[j] = 1 + ahead[j + 1];
                else curr[j] = max(ahead[j],curr[j + 1]);
            }
            ahead = curr;
        }
        return ahead[0];
    }
    int longestCommonSubsequence(string text1,string text2){
        // return lcs_rec(0,0,text1,text2);
        // return lcs_tab(text1,text2);
        return lcs_space(text1,text2);
    }
};
