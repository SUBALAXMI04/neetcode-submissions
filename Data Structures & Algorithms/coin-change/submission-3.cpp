class Solution {
public:
    int coin_rec(int idx,int amt,vector<int>& coins){
        if(idx == 0){
            if(amt % coins[0] == 0) return amt/coins[0];
            return 1e9;
        }
        int take = (coins[idx] <= amt) ? 1 + coin_rec(idx,amt - coins[idx],coins) : 1e9;
        int notTake = coin_rec(idx - 1,amt,coins);
        return min(take,notTake);
    }
    int coin_tab(int amt,vector<int>& coins){
        int n = coins.size();
        vector<vector<int>> dp(n + 1,vector<int>(amt + 1,1e9));
        dp[0][0] = 0;
        for(int t = coins[0];t <= amt;t++){
            if(t % coins[0] == 0) dp[0][t] = t/coins[0];
        }
        for(int idx = 1;idx < n;idx++){
            for(int t = 0;t <= amt;t++){
                int take = (t >= coins[idx]) ? 1 + dp[idx][t - coins[idx]] : 1e9;
                int notTake = dp[idx - 1][t];
                dp[idx][t] = min(take,notTake);
            }
        }
        return dp[n - 1][amt];
    }
    int coinChange(vector<int>& coins,int amt){
        int n = coins.size();
        // int ans = coin_rec(n - 1,amt,coins);
        int ans = coin_tab(amt,coins);
        return (ans >= 1e9) ? -1 : ans;
    }
};
