class Solution {
public:
    int min_rec(int idx,vector<int>& cost){
        if(idx >= cost.size()) return 0;
        int one = min_rec(idx + 1,cost);
        int two = min_rec(idx + 2,cost);
        return cost[idx] + min(one,two);
    }
    int min_tab(vector<int>& cost){
        int n = cost.size();
        vector<int> dp(n + 1,0);
        dp[0] = cost[0]; dp[1] = cost[1];
        for(int i = 2;i < n;i++) dp[i] = cost[i] + min(dp[i - 1],dp[i - 2]);
        return min(dp[n - 2],dp[n - 1]);
    }
    int min_space(vector<int>& cost){
        int n = cost.size();
        int prev1 = cost[1],prev2 = cost[0];
        for(int i = 2;i < n;i++){
            int curr = cost[i] + min(prev1,prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev1,prev2);
    }
    int minCostClimbingStairs(vector<int>& cost){
        // return min(min_rec(0,cost),min_rec(1,cost));
        if(cost.size() == 1) return cost[0];
        else if(cost.size() == 2) return min(cost[0],cost[1]);
        // return min_tab(cost);
        return min_space(cost);
    }
};
