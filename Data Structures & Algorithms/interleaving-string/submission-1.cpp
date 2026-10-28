class Solution {
public:
    bool leave_rec(int i1,int i2,string s1,string s2,string t){
        if(i1 == s1.size() && i2 == s2.size()) return (i1 + i2 == t.size());
        if(i1 == s1.size()) return s2.substr(i2) == t.substr(i1 + i2);
        if(i2 == s2.size()) return s1.substr(i1) == t.substr(i1 + i2);
        bool ans = false;
        if(s1[i1] == t[i1 + i2]) ans = leave_rec(i1 + 1,i2,s1,s2,t);
        if(s2[i2] == t[i1 + i2]) ans = ans || leave_rec(i1,i2 + 1,s1,s2,t);
        return ans;
    }
    bool leave_tab(string s1,string s2,string t){
        int n1 = s1.size(),n2 = s2.size(),m = t.size();
        vector<vector<bool>> dp(n1 + 1,vector<bool>(n2 + 1,false));
        dp[n1][n2] = true;
        for(int j = 0;j < n2;j++)
            dp[n1][j] = (s2.substr(j) == t.substr(n1 + j));
        for(int i = 0;i < n1;i++)
            dp[i][n2] = (s1.substr(i) == t.substr(i + n2));
        for(int i = n1 - 1;i >= 0;i--){
            for(int j = n2 - 1;j >= 0;j--){
                bool ans = false;
                if(s1[i] == t[i + j]) ans = dp[i + 1][j];
                if(s2[j] == t[i + j]) ans = ans || dp[i][j + 1];
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    bool leave_space(string s1,string s2,string t){
        int n1 = s1.size(),n2 = s2.size(),m = t.size();
        vector<bool> curr(n2 + 1,false),ahead(n2 + 1,false);
        ahead[n2] = true;
        for(int j = 0;j < n2;j++)
            ahead[j] = (s2.substr(j) == t.substr(n1 + j));
        for(int i = n1 - 1;i >= 0;i--){
            curr[n2] = (s1.substr(i) == t.substr(i + n2));
            for(int j = n2 - 1;j >= 0;j--){
                bool ans = false;
                if(s1[i] == t[i + j]) ans = ahead[j];
                if(s2[j] == t[i + j]) ans = ans || curr[j + 1];
                curr[j] = ans;
            }
            ahead = curr;
        }
        return ahead[0];
    }
    bool isInterleave(string s1,string s2,string s3){
        if(s1.size() + s2.size() != s3.size()) return false;
        // return leave_rec(0,0,0,s1,s2,s3);
        // return leave_tab(s1,s2,s3);
        return leave_space(s1,s2,s3);
    }
};
