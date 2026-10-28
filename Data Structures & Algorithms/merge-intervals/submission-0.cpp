class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& I){
        vector<vector<int>> ans;
        int n = I.size();
        sort(I.begin(),I.end());
        for(int i = 0;i < n;i++){
            if(ans.empty() || ans.back()[1] < I[i][0]) ans.push_back(I[i]);
            else ans.back()[1] = max(ans.back()[1],I[i][1]);
        }
        return ans;
    }
};
