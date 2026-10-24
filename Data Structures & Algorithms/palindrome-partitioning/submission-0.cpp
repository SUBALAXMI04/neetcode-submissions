class Solution {
public:
    bool isPal(string &s,int l,int r){
        while(l < r){
            if(s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }
    void dfs(int idx,string &s,vector<string>& curr,vector<vector<string>>& ans){
        if(idx >= s.size()){
            ans.push_back(curr);
            return;
        }
        for(int j = idx;j < s.size();j++){
            if(isPal(s,idx,j)){
                curr.push_back(s.substr(idx,j - idx + 1));
                dfs(j + 1,s,curr,ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s){
        vector<vector<string>> ans;
        vector<string> curr;
        dfs(0,s,curr,ans);
        return ans;
    }
};
