class Solution {
public:
    bool match_rec(int i,int j,string s,string p){
        if(j == p.size()) return (i == s.size());
        bool match = i < s.size() && (s[i] == p[j] || p[j] == '.');
        if(j + 1 < p.size() && p[j + 1] == '*')
            return match_rec(i,j + 2,s,p) || (match && match_rec(i + 1,j,s,p));
        return match && match_rec(i + 1,j + 1,s,p);
    }
    bool match_tab(string s,string p){
        int n = s.size(),m = p.size();
        vector<vector<bool>> dp(n + 1,vector<bool>(m + 1,false));
        dp[n][m] = true;
        for(int j = 0;j < m - 1;j++){
            if(p[j + 1] == '*') dp[n][j] = dp[n][j + 2];
        }
        for(int i = n - 1;i >= 0;i--){
            for(int j = m - 1;j >= 0;j--){
                bool match = (s[i] == p[j] || p[j] == '.');
                if(j != m - 1 && p[j + 1] == '*')
                    dp[i][j] = dp[i][j + 2] || (match && dp[i + 1][j]);
                else dp[i][j] = match && dp[i + 1][j + 1];
            }
        }
        return dp[0][0];
    }
    bool match_space(string s,string p){
        int n = s.size(),m = p.size();
        vector<bool> curr(m + 1,false),ahead(m + 1,false);
        ahead[m] = true;
        for(int j = 0;j < m - 1;j++){
            if(p[j + 1] == '*') ahead[j] = ahead[j + 2];
        }
        for(int i = n - 1;i >= 0;i--){
            for(int j = m - 1;j >= 0;j--){
                bool match = (s[i] == p[j] || p[j] == '.');
                if(j != m - 1 && p[j + 1] == '*')
                    curr[j] = curr[j + 2] || (match && ahead[j]);
                else curr[j] = match && ahead[j + 1];
            }
            ahead = curr;
            fill(curr.begin(),curr.end(),false);
        }
        return ahead[0];
    }
    bool isMatch(string s,string p){
        // return match_rec(0,0,s,p);
        return match_tab(s,p);
    }
};
