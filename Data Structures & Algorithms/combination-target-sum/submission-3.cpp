class Solution {
public:
    void solve(int idx,int target,vector<int>& nums,vector<int>& curr,vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        if(idx == nums.size() || target < 0) return;
        solve(idx + 1,target,nums,curr,ans);
        curr.push_back(nums[idx]);
        solve(idx,target - nums[idx],nums,curr,ans);
        curr.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& nums,int target){
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(),nums.end());
        solve(0,target,nums,curr,ans);
        return ans;
    }
};