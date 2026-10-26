class Solution {
public:
    int rob_rec(int idx,vector<int>& nums){
        if(idx >= nums.size()) return 0;
        int take = nums[idx] + rob_rec(idx + 2,nums);
        int notTake = rob_rec(idx + 1,nums);
        return max(take,notTake);
    }
    int rob_tab(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n,0);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i = 2;i < n;i++) dp[i] = max(nums[i] + dp[i - 2],dp[i - 1]);
        return max(dp[n - 1],dp[n - 2]);
    }
    int rob(vector<int>& nums){
        if(nums.size() == 1) return nums[0];
        else if(nums.size() == 2) return max(nums[0],nums[1]);
        // return rob_rec(0,nums);
        return rob_tab(nums);
    }
};
