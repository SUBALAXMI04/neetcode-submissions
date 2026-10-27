class Solution {
public:
    int profit_rec(int idx,int cnt,vector<int>& prices){
        if(idx == prices.size()) return 0;
        int take = -1e9,notTake = -1e9;
        if(cnt == 1){
            take = prices[idx] + profit_rec(idx + 1,2,prices);
            notTake = profit_rec(idx + 1,1,prices);
        } else {
            if(cnt == 0) take = -prices[idx] + profit_rec(idx + 1,1,prices);
            notTake = profit_rec(idx + 1,0,prices); 
        }
        return max(take,notTake);
    }
    int profit_tab(vector<int>& prices){
        int n = prices.size();
        vector<vector<int>> dp(n + 1,vector<int>(3,0));
        for(int idx = n - 1;idx >= 0;idx--){
            int take = -1e9,notTake = -1e9;
            dp[idx][0] = max(-prices[idx] + dp[idx + 1][1],dp[idx + 1][0]); 
            dp[idx][1] = max(prices[idx] + dp[idx + 1][2],dp[idx + 1][1]);
            dp[idx][2] = dp[idx + 1][0];
        }
        return dp[0][0];
    }
    int profit_space(vector<int>& prices){
        int n = prices.size();
        vector<int> curr(3,0),ahead(3,0);
        for(int idx = n - 1;idx >= 0;idx--){
            int take = -1e9,notTake = -1e9;
            curr[0] = max(-prices[idx] + ahead[1],ahead[0]); 
            curr[1] = max(prices[idx] + ahead[2],ahead[1]);
            curr[2] = ahead[0];
            ahead = curr;
        }
        return ahead[0];
    }
    int maxProfit(vector<int>& prices){
        // return profit_rec(0,0,prices);
        // return profit_tab(prices);
        return profit_space(prices);
    }
};
