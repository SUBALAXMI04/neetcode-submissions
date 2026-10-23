class Solution {
public:
    void backtrack(int idx,vector<int>& nums,vector<vector<int>>& ans){
        if(idx == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = idx;i < nums.size();i++){
            swap(nums[idx],nums[i]);
            backtrack(idx + 1,nums,ans);
            swap(nums[idx],nums[i]);
        }
    }
    void backtrack2(vector<int>& nums,vector<int>& perm,int mask,vector<vector<int>>& ans){
        if(perm.size() == nums.size()){
            ans.push_back(perm);
            return;
        }
        for(int i = 0;i < nums.size();i++){
            if(!(mask & (1 << i))){
                perm.push_back(nums[i]);
                backtrack2(nums,perm,mask | (1 << i),ans);
                perm.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums){
        vector<vector<int>> ans;
        vector<int> perm;
        // backtrack(0,nums,ans);
        backtrack2(nums,perm,0,ans);
        return ans;
    }
};
