class Solution {
public:
    int coin_rec(int idx,int amt,vector<int>& coins){
        if(amt == 0) return 1;
        if(idx == 0) return (amt % coins[0] == 0);
        int take = (amt >= coins[idx]) ? coin_rec(idx,amt - coins[idx],coins) : 0;
        int notTake = coin_rec(idx - 1,amt,coins);
        return take + notTake;
    }
    int coin_tab(int amt,vector<int>& coins){
        int n = coins.size();
        vector<vector<int>> dp(n + 1,vector<int>(amt + 1,0));
        for(int idx = 0;idx < n;idx++) dp[idx][0] = 1;
        for(int t = 0;t <= amt;t++) dp[0][t] = (t % coins[0] == 0);
        for(int idx = 1;idx < n;idx++){
            for(int t = 1;t <= amt;t++){
                int take = (t >= coins[idx]) ? dp[idx][t - coins[idx]] : 0;
                int notTake = dp[idx - 1][t];
                dp[idx][t] = take + notTake;
            }
        }
        return dp[n - 1][amt];
    }
    int change(int amt,vector<int>& coins){
        int n = coins.size();
        // return coin_rec(n - 1,amt,coins);
        return coin_tab(amt,coins);
        // return coin_space(amt,coins);
    }
};
