class Solution {
public:
    int findMin(vector<int> &nums){
        int st = 0,end = nums.size() - 1,mini = 1e9;
        while(st <= end){
            int mid = st + (end - st)/2;
            if(nums[st] <= nums[mid]){
                mini = min(mini,nums[st]);
                st = mid + 1;
            }
            else{
                mini = min(mini,nums[mid]);
                end = mid - 1;
            }
        }
        return mini;
    }
};
