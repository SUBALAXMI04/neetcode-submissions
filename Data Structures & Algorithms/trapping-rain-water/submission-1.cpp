class Solution {
public:
    int trap(vector<int>& H){
        int n = H.size(),maxi = 0,Lmax = H[0];
        vector<int> Rmax(n);
        Rmax[n - 1] = H[n - 1];
        for(int i = n - 2;i >= 0;i--) Rmax[i] = max(Rmax[i + 1],H[i]);
        for(int i = 0;i < n;i++){
            Lmax = max(Lmax,H[i]);
            maxi += min(Rmax[i],Lmax) - H[i];
        }
        return maxi;
    }
};
