class Solution {
public:
    int lengthOfLongestSubstring(string s){
        vector<int> idx(256,-1);
        int l = 0,n = s.size(),maxi = 0;
        for(int r = 0;r < n;r++){
            if(idx[(unsigned char)s[r]] != -1) l = max(l,idx[(unsigned char)s[r]] + 1);
            idx[(unsigned char)s[r]] = r;
            maxi = max(maxi,r - l + 1);
        }
        return maxi;
    }
};
