class Solution {
public:
    bool sum_rec(int idx,int tgt,vector<int>& nums){
        if(tgt == 0) return true;
        if(idx == nums.size()) return (tgt == 0);
        bool take = false,notTake = sum_rec(idx + 1,tgt,nums);
        if(nums[idx] <= tgt) take = sum_rec(idx + 1,tgt - nums[idx],nums);
        return take || notTake;
    }
    bool sum_tab(int tgt,vector<int>& nums){
        int n = nums.size();
        vector<vector<bool>> dp(n + 1,vector<bool>(tgt + 1,false));
        for(int i = 0;i <= n;i++) dp[i][0] = true;
        for(int idx = n - 1;idx >= 0;idx--){
            for(int t = 1;t <= tgt;t++){
                bool take = false,notTake = dp[idx + 1][t];
                if(nums[idx] <= t) take = dp[idx + 1][t - nums[idx]];
                dp[idx][t] = take || notTake;
            }
        }
        return dp[0][tgt];
    }
    bool sum_space(int tgt,vector<int>& nums){
        int n = nums.size();
        vector<bool> curr(tgt + 1,false),ahead(tgt + 1,false);
        ahead[0] = true;
        for(int idx = n - 1;idx >= 0;idx--){
            fill(curr.begin(),curr.end(),false);
            curr[0] = true;
            for(int t = 1;t <= tgt;t++){
                bool take = false,notTake = ahead[t];
                if(nums[idx] <= t) take = ahead[t - nums[idx]];
                curr[t] = take || notTake;
            }
            ahead = curr;
        }
        return ahead[tgt];
    }
    bool canPartition(vector<int>& nums){
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % 2) return false;
        int X = sum/2;
        // return sum_rec(0,X,nums);
        // return sum_tab(X,nums);
        return sum_space(X,nums);
    }
};
