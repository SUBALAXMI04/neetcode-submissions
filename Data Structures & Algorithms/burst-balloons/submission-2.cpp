class Solution {
public:
    int coin_rec(int l,int r,vector<int>& nums){
        if(l > r) return 0; 
        int ans = 0;
        for(int i = l;i <= r;i++){
            int num = coin_rec(l,i - 1,nums) + nums[l - 1]*nums[i]*nums[r + 1] + 
                    coin_rec(i + 1,r,nums);
            ans = max(ans,num);
        }
        return ans;
    }
    int coin_tab(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int len = 1;len <= n - 2;len++){
            for(int l = 1;len + l - 1 <= n - 2;l++){
                int r = len + l - 1;
                for(int i = l;i <= r;i++){
                    int X = dp[l][i - 1] + nums[l - 1]*nums[i]*nums[r + 1] + dp[i + 1][r];
                    dp[l][r] = max(X,dp[l][r]);
                }
            }
        }
        return dp[1][n - 2];
    }
    int maxCoins(vector<int>& nums){
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        // return coin_rec(1,nums.size() - 2,nums);
        return coin_tab(nums);
    }
};
