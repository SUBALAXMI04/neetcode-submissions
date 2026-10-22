class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int> st(nums.begin(),nums.end());
        int maxi = 1;
        for(auto it : st){
            if(st.count(it - 1)) continue;
            int curr = it,cnt = 0;
            while(st.count(curr)){
                curr++;
                cnt++;
            }
            maxi = max(maxi,cnt);
        }
        return maxi;
    }
};
