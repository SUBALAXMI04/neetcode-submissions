class Solution {
public:
    int singleNumber(vector<int>& nums){
        int xor_ = 0;
        for(int x : nums) xor_ = xor_ ^ x;
        return xor_;
    }
};
