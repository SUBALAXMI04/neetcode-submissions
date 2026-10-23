class Solution {
public:
    void solve(int idx,int total,int target,vector<int>& nums,vector<int>& curr,vector<vector<int>>& ans){
        if(target == total){
            ans.push_back(curr);
            return;
        }
        if(idx == nums.size() || target < 0) return;
        for(int j = idx;j < nums.size();j++){
            if(total + nums[j] > target) return;
            curr.push_back(nums[j]);
            solve(j,total + nums[j],target,nums,curr,ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums,int target){
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(),nums.end());
        solve(0,0,target,nums,curr,ans);
        return ans;
    }
};