class Solution {
public:
    int num_rec(int i,int j,string s,string t){
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;
        int take = 0,notTake = num_rec(i + 1,j,s,t);
        if(s[i] == t[j]) take = num_rec(i + 1,j + 1,s,t);
        return take + notTake;
    }
    int num_tab(string s,string t){
        int n = s.size(),m = t.size();
        vector<vector<long long>> dp(n + 1,vector<long long>(m + 1,0));
        for(int i = 0;i <= n;i++) dp[i][m] = 1;
        for(int i = n - 1;i >= 0;i--){
            for(int j = m - 1;j >= 0;j--){
                long long take = 0,notTake = dp[i + 1][j];
                if(s[i] == t[j]) take = dp[i + 1][j + 1];
                dp[i][j] = take + notTake;
            }
        }
        return dp[0][0];
    }
    int num_space(string s,string t){
        int n = s.size(),m = t.size();
        vector<long long> curr(m + 1,0),ahead(m + 1,0);
        ahead[m] = 1;
        for(int i = n - 1;i >= 0;i--){
            curr[m] = 1;
            for(int j = m - 1;j >= 0;j--){
                long long take = 0,notTake = ahead[j];
                if(s[i] == t[j]) take = ahead[j + 1];
                curr[j] = take + notTake;
            }
            ahead = curr;
            fill(curr.begin(),curr.end(),0);
        }
        return ahead[0];
    }
    int numDistinct(string s,string t){
        // return num_rec(0,0,s,t);
        // return num_tab(s,t);
        return num_space(s,t);
    }
};
