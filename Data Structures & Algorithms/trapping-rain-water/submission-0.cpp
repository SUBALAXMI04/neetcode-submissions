class Solution {
public:
    int trap(vector<int>& H){
        int n = H.size(),maxi = 0;
        vector<int> Rmax(n),Lmax(n);
        Lmax[0] = H[0];
        for(int i = 1;i < n;i++) Lmax[i] = max(Lmax[i - 1],H[i]);
        Rmax[n - 1] = H[n - 1];
        for(int i = n - 2;i >= 0;i--) Rmax[i] = max(Rmax[i + 1],H[i]);
        for(int i = 0;i < n;i++) maxi += min(Rmax[i],Lmax[i]) - H[i];
        return maxi;
    }
};
