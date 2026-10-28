class Solution {
public:
    int dist_rec(int i,int j,string s,string t){
        if(j == t.size()) return s.size() - i;
        if(i == s.size()) return t.size() - j;
        if(s[i] == t[j]) return dist_rec(i + 1,j + 1,s,t);
        int ins = 1 + dist_rec(i,j + 1,s,t);
        int del = 1 + dist_rec(i + 1,j,s,t);
        int rep = 1 + dist_rec(i + 1,j + 1,s,t);
        return min({ins,del,rep});
    }
    int dist_tab(string s,string t){
        int n = s.size(),m = t.size();
        vector<vector<int>> dp(n + 1,vector<int>(m + 1,0));
        for(int i = 0;i <= n;i++) dp[i][m] = n - i;
        for(int j = 0;j <= m;j++) dp[n][j] = m - j;
        for(int i = n - 1;i >= 0;i--){
            for(int j = m - 1;j >= 0;j--){
                if(s[i] == t[j]) dp[i][j] = dp[i + 1][j + 1];
                else{
                    int ins = 1 + dp[i][j + 1];
                    int del = 1 + dp[i + 1][j];
                    int rep = 1 + dp[i + 1][j + 1];
                    dp[i][j] = min({ins,del,rep});
                }
            }
        }
        return dp[0][0];
    }
    int dist_space(string s,string t){
        int n = s.size(),m = t.size();
        vector<int> curr(m + 1,0),ahead(m + 1,0);
        for(int j = 0;j <= m;j++) ahead[j] = m - j;
        for(int i = n - 1;i >= 0;i--){
            curr[m] = n - i;
            for(int j = m - 1;j >= 0;j--){
                if(s[i] == t[j]) curr[j] = ahead[j + 1];
                else curr[j] = 1 + min({curr[j + 1],ahead[j],ahead[j + 1]});
            }
            ahead = curr;
            fill(curr.begin(),curr.end(),0);
        }
        return ahead[0];
    }
    int minDistance(string s1,string s2){
        // return dist_rec(0,0,s1,s2);
        // return dist_tab(s1,s2);
        return dist_space(s1,s2);
    }
};
