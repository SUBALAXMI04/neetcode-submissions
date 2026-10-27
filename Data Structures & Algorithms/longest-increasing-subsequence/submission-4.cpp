class Solution {
public:
    int lis_rec(int idx,int last,vector<int>& nums){
        if(idx == nums.size()) return 0;
        int take = -1e9;
        if(last == -1 || nums[idx] > nums[last]) take = 1 + lis_rec(idx + 1,idx,nums);
        int notTake = lis_rec(idx + 1,last,nums);
        return max(take,notTake);
    }
    int lis_tab(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> dp(n + 1,vector<int>(n + 1,0));
        for(int idx = n - 1;idx >= 0;idx--){
            for(int last = idx - 1;last >= -1;last--){
                int take = -1e9,notTake = dp[idx + 1][last + 1];
                if(last == -1 || nums[idx] > nums[last]) take = 1 + dp[idx + 1][idx + 1];
                dp[idx][last + 1] = max(take,notTake);
            }
        }
        return dp[0][-1 + 1];
    }
    int lengthOfLIS(vector<int>& nums){
        // return lis_rec(0,-1,nums);
        return lis_tab(nums);
    }
};
