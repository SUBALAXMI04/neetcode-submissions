class Solution {
public:
    int decode(int idx,string s){
        if(idx == s.size()) return 1;
        int one = 0,two = 0;
        if(s[idx] != '0') one = decode(idx + 1,s);
        if(idx + 1 < s.size()){
            int num = stoi(s.substr(idx,2));
            if(num >= 1 && num <= 26) two = decode(idx + 2,s);
        }
        return one + two;
    }
    int decode_tab(string s){
        int n = s.size();
        vector<int> dp(n + 1,0);
        dp[n] = 1;
        for(int i = n - 1;i >= 0;i--){
            if(s[i] == '0') dp[i] = 0;
            else{
                dp[i] = dp[i + 1];
                if(i != n - 1){
                    int num = stoi(s.substr(i,2));
                    if(num >= 1 && num <= 26) dp[i] += dp[i + 2];
                }
            }
        }
        return dp[0];
    }
    int decode_space(string s){
        int n = s.size();
        vector<int> dp(n + 1,0);
        dp[n] = 1;
        for(int i = n - 1;i >= 0;i--){
            if(s[i] == '0') dp[i] = 0;
            else{
                dp[i] = dp[i + 1];
                if(i != n - 1){
                    int num = stoi(s.substr(i,2));
                    if(num >= 1 && num <= 26) dp[i] += dp[i + 2];
                }
            }
        }
        return dp[0];
    }
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        // return decode(0,s);
        return decode_tab(s);
    }
};
