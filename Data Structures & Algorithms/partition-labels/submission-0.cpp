class Solution {
public:
    vector<int> partitionLabels(string s){
        int n = s.size();
        vector<int> last(26,-1),ans;
        for(int i = 0;i < n;i++) last[s[i] - 'a'] = i;
        for(int l = 0;l < n;){
            int r = last[s[l] - 'a'];
            for(int i = l;i <= r;i++) r = max(r,last[s[i] - 'a']);
            ans.push_back(r - l + 1);
            l = r + 1;
        }
        return ans;
    }
};
