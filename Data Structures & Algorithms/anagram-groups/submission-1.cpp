class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> ans;
        for(string &s : strs){
            vector<int> freq(26,0);
            for(char c : s) freq[c - 'a']++;
            string X;
            for(int i : freq) X.push_back(char(i + '0'));
            mp[X].push_back(s);
        }
        for(auto p : mp) ans.push_back(p.second);
        return ans;
    }
};
