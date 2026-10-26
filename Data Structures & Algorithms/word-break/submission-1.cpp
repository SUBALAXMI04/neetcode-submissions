class Solution {
public:
    bool break_rec(int idx,string s,unordered_set<string>& st){
        if(idx == s.size()) return true;
        string word;
        for(int i = idx;i < s.size();i++){
            word += s[i];
            if(st.count(word)){
                if(break_rec(i + 1,s,st)) return true;
            }
        }
        return false;
    }
    bool break_tab(string s,unordered_set<string>& st){
        int n = s.size();
        vector<bool> dp(n + 1,false);
        dp[n] = true;
        for(int start = n - 1;start >= 0;start--){
            string word;
            for(int end = start;end < s.size();end++){
                word += s[end];
                if(st.count(word) != 0 && dp[end + 1]){
                    dp[start] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        // return break_rec(0,s,st);
        return break_tab(s,st);
    }
};
