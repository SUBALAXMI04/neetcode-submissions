class Solution {
public:
    void solve(int idx,vector<int>& nums,vector<int>& curr,vector<vector<int>>& ans){
        if(idx == nums.size()){
            ans.push_back(curr);
            return;
        }
        solve(idx + 1,nums,curr,ans);
        curr.push_back(nums[idx]);
        solve(idx + 1,nums,curr,ans);
        curr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0,nums,curr,ans);
        return ans;
    }
};
