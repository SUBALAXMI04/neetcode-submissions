class Solution {
public:
    int lengthOfLongestSubstring(string s){
        vector<int> idx(256,-1);
        int l = 0,n = s.size(),maxi = 0;
        for(int r = 0;r < n;r++){
            if(idx[s[r]] != -1) l = max(l,idx[s[r]] + 1);
            idx[s[r]] = r;
            maxi = max(maxi,r - l + 1);
        }
        return maxi;
    }
};
