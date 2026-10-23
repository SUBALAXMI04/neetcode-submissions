class Solution {
public:
    int leastInterval(vector<char>& tasks,int n){
        vector<int> freq(26,0);
        int maxFreq = 0,cnt = 0;
        for(auto c : tasks){
            freq[c - 'A']++;
            maxFreq = max(maxFreq,freq[c - 'A']);
        }
        for(int i : freq){
            if(i == maxFreq) cnt++;
        }
        return max((int)tasks.size(),(maxFreq - 1)*(n + 1) + cnt);
    }
};
