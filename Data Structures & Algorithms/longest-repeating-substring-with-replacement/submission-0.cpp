class Solution {
public:
    int characterReplacement(string s,int k){
        int n = s.size(),l = 0,maxFreq = 0,maxi = 0;
        vector<int> freq(26,0);
        for(int r = 0;r < n;r++){
            freq[s[r] - 'A']++;
            maxFreq = max(maxFreq,freq[s[r] - 'A']);
            while(r - l + 1 - maxFreq > k){
                freq[s[l++] - 'A']--;
                maxFreq = 0;
                for(int i = 0;i < 26;i++) maxFreq = max(maxFreq,freq[i]);
            }
            maxi = max(maxi,r - l + 1);
        }
        return maxi;
    }
};
