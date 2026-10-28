class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& I, vector<int>& newI){
        int n = I.size(),i = 0;
        vector<vector<int>> ans;
        while(i < n && I[i][1] < newI[0]) ans.push_back(I[i++]);
        while(i < n && I[i][0] <= newI[1]){
            newI[0] = min(newI[0],I[i][0]);
            newI[1] = max(newI[1],I[i][1]);
            i++;
        }
        ans.push_back(newI);
        while(i < n) ans.push_back(I[i++]);
        return ans;
    }
};
