class Solution {
public:
    string minWindow(string s,string t){
        if(s.size() < t.size()) return "";
        int n = s.size(),m = t.size();
        vector<int> freq(256,0);
        for(char c : t) freq[c]++;
        int cnt = 0,stIdx = -1,minLen = INT_MAX,l = 0;
        for(int r = 0;r < n;r++){
            freq[s[r]]--;
            if(freq[s[r]] >= 0) cnt++;
            while(cnt == m){
                if(minLen > r - l + 1){
                    minLen = r - l + 1;
                    stIdx = l;
                }
                freq[s[l]]++;
                if(freq[s[l]] > 0) cnt--;
                l++;
            }
        }
        return (stIdx == -1) ? "" : s.substr(stIdx,minLen);
    }
};
