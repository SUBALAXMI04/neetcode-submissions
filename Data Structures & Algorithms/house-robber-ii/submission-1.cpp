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
    int rob_space(vector<int>& nums){
        int n = nums.size();
        int prev2 = nums[0],prev1 = max(nums[0],nums[1]);
        for(int i = 2;i < n;i++){
            int curr = max(nums[i] + prev2,prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return max(prev1,prev2);
    }
    int rob(vector<int>& nums){
        int n = nums.size();
        if(n == 1) return nums[0];
        else if(n == 2) return max(nums[0],nums[1]);
        vector<int> nums1,nums2;
        for(int i = 0;i < n;i++){
            if(i != 0) nums2.push_back(nums[i]);
            if(i != n - 1) nums1.push_back(nums[i]);
        }
        // return max(rob_rec(0,nums1),rob_rec(0,nums2));
        return max(rob_tab(nums1),rob_tab(nums2));
        // return rob_space(nums);
    }
};
