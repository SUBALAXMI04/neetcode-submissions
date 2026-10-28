class Solution {
public:
    int sum_rec(int idx,bool flag,vector<int>& nums){
        if(idx == nums.size() - 1) return flag ? max(0,nums[idx]) : nums[idx];
        if(flag) return max(0,nums[idx] + sum_rec(idx + 1,true,nums));
        return max(nums[idx] + sum_rec(idx + 1,true,nums),sum_rec(idx + 1,false,nums));
    }
    int sum_tab(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(2,0));
        dp[n - 1][0] = nums[n - 1];
        dp[n - 1][1] = max(0,nums[n - 1]);
        for(int idx = n - 2;idx >= 0;idx--){
            dp[idx][1] = max(0,nums[idx] + dp[idx + 1][1]);
            dp[idx][0] = max(nums[idx] + dp[idx + 1][1],dp[idx + 1][0]);
        }
        return dp[0][0];
    }
    int sum_space(vector<int>& nums){
        int n = nums.size();
        vector<int> curr = {nums[n - 1],max(0,nums[n - 1])};
        for(int idx = n - 2;idx >= 0;idx--){
            curr[0] = max(nums[idx] + curr[1],curr[0]);
            curr[1] = max(0,nums[idx] + curr[1]);
        }
        return curr[0];
    }
    int maxSubArray(vector<int>& nums){
        // int n = nums.size(),ans = nums[0],curr = nums[0];
        // for(int i = 1;i < n;i++){
        //     curr = max(nums[i],curr + nums[i]);
        //     ans = max(ans,curr);
        // }
        // return ans;

        // return sum_rec(0,false,nums);
        // return sum_tab(nums);
        return sum_space(nums);
    }
};
