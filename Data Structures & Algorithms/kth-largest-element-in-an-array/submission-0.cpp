class Solution {
public:
    int findKthLargest(vector<int>& nums,int k){
        int st = 0,end = nums.size() - 1,n = nums.size();
        while(st <= end){
            int pivotIdx = st + rand() % (end - st + 1);
            swap(nums[end],nums[pivotIdx]);
            int idx = st;
            for(int i = st;i < end;i++){
                if(nums[i] < nums[end]) swap(nums[i],nums[idx++]);
            }
            swap(nums[idx],nums[end]);
            if(idx == n - k) return nums[idx];
            else if(idx < n - k) st = idx + 1;
            else end = idx - 1;
        }
        return nums[0];
    }
};
