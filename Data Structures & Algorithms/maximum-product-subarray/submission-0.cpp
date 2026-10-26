class Solution {
public:
    int maxProduct(vector<int>& nums){
        int n = nums.size(),mini = nums[0],maxi = nums[0],ans = nums[0];
        for(int i = 1;i < n;i++){
            if(nums[i] < 0) swap(mini,maxi);
            if(mini == 0) mini = 1;
            if(maxi == 0) maxi = 1;
            mini = min(mini * nums[i],nums[i]);
            maxi = max(maxi * nums[i],nums[i]);
            ans = max(ans,maxi);
        }
        return ans;
    }
};
