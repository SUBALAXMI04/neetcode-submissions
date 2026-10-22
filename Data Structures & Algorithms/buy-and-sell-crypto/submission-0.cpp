class Solution {
public:
    int maxProfit(vector<int>& prices){
        int mini = 1e9,maxProf = 0;
        for(int p : prices){
            mini = min(mini,p);
            maxProf = max(maxProf,p - mini);
        }
        return maxProf;
    }
};
