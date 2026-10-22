class Solution {
public:
    bool checkInclusion(string s1,string s2){
        if(s2.size() < s1.size()) return false;
        int m = s1.size(),n = s2.size();
        vector<int> freq1(26,0),freq2(26,0);
        for(char c : s1) freq1[c - 'a']++;
        for(int i = 0;i < m - 1;i++) freq2[s2[i] - 'a']++;
        for(int i = m - 1;i < n;i++){
            freq2[s2[i] - 'a']++;
            if(freq1 == freq2) return true;
            freq2[s2[i - m + 1] - 'a']--;
        }
        return false;
    }
};
