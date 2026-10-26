class Solution {
public:
    int climb_rec(int n){
        if(n <= 2) return n;
        return climb_rec(n - 2) + climb_rec(n - 1);
    }
    int climb_tab(int n){
        if(n <= 2) return n;
        vector<int> dp(n + 1,0);
        dp[1] = 1; dp[2] = 2;
        for(int i = 3;i <= n;i++) dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
    int climb_space(int n){
        if(n <= 2) return n;
        int prev1 = 2,prev2 = 1,curr = 0;
        for(int i = 3;i <= n;i++){
            curr = prev2 + prev1;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int climbStairs(int n){
        // return climb_rec(n);
        // return climb_tab(n);
        return climb_space(n);
    }
};
