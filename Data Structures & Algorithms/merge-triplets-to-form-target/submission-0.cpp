class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& T,vector<int>& X){
        vector<int> ans = {0,0,0};
        for(auto& e : T){
            if(e[0] > X[0] || e[1] > X[1] || e[2] > X[2]) continue;
            if(e[0] == X[0] || e[1] == X[1] || e[2] == X[2]){
                ans[0] = max(ans[0],e[0]);
                ans[1] = max(ans[1],e[1]);
                ans[2] = max(ans[2],e[2]);
            }
        }
        return ans == X;
    }
};
