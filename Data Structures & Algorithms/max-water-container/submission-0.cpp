class Solution {
public:
    int maxArea(vector<int>& H){
        int ans = 0,l = 0,r = H.size() - 1;
        while(l < r){
            int area = min(H[l],H[r]) * (r - l);
            ans = max(ans,area);
            if(H[l] <= H[r]) l++;
            else r--;
        }
        return ans;
    }
};
