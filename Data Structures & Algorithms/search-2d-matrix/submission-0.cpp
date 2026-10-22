class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat,int target){
        int st = 0,end = mat.size() - 1,row = 0;
        while(st <= end){
            int mid = st + (end - st)/2;
            if(mat[mid][0] == target) return true;
            else if(mat[mid][0] < target){
                row = mid;
                st = mid + 1;
            }
            else end = mid - 1;
        }
        st = 0; end = mat[0].size() - 1;
        while(st <= end){
            int mid = st + (end - st)/2;
            if(mat[row][mid] == target) return true;
            else if(mat[row][mid] < target) st = mid + 1;
            else end = mid - 1;
        }
        return false;
    }
};
