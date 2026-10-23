class Solution {
public:
    vector<vector<int>> ans;
    void solve(int idx,int sum,int target,vector<int>& nums,vector<int>& curr){
        if(target == sum){
            ans.push_back(curr);
            return;
        }
        if(target < sum || idx == nums.size()) return;
        for(int j = idx;j < nums.size();j++){
            if(j != idx && nums[j] == nums[j - 1]) continue;
            if(sum + nums[j] > target) return;
            curr.push_back(nums[j]);
            solve(j + 1,sum + nums[j],target,nums,curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums,int target){
        vector<int> curr;
        sort(nums.begin(),nums.end());
        solve(0,0,target,nums,curr);
        return ans;
    }
};