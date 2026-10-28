class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(),jump = 0,maxi = 0,curr = 0;
        for(int i = 0;i < n - 1;i++){
            maxi = max(maxi,i + nums[i]);
            if(curr == i){
                curr = maxi;
                jump++;
            }
        }
        return jump;
    }
};
