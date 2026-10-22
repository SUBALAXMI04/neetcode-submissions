class Solution {
public:
    int trap(vector<int>& H){
        int l = 0,r = H.size() - 1,ans = 0;
        int Lmax = H[l],Rmax = H[r];
        while(l < r){
            if(Lmax <= Rmax){
                Lmax = max(Lmax,H[++l]);
                ans += Lmax - H[l];
            } else{
                Rmax = max(Rmax,H[--r]);
                ans += Rmax - H[r];
            }
        }
        return ans;
    }
};
