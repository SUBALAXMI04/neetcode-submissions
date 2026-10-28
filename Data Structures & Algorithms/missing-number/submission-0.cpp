class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(),xor_ = 0;
        for(int i = 0;i < n;i++) xor_ = xor_ ^ nums[i] ^ (i + 1);
        return xor_;
    }
};
