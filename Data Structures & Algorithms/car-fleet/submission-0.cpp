class Solution {
public:
    int carFleet(int target,vector<int>& pos,vector<int>& speed){
        int n = pos.size();
        vector<pair<int,int>> X(n);
        for(int i = 0;i < n;i++) X[i] = {pos[i],speed[i]};
        sort(X.rbegin(),X.rend());
        int ans = 1;
        double ahead = (target - X[0].first)/X[0].second;
        for(int i = 1;i < n;i++){
            double curr = (double)(target - X[i].first)/(double)X[i].second;
            if(ahead < curr){
                ans++;
                ahead = curr;
            }
        }
        return ans;
    }
};
