class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat){
        int left = 0,right = mat[0].size() - 1,top = 0,down = mat.size() - 1;
        vector<int> temp;
        while(left <= right && top <= down){
            for(int j = left;j <= right;j++) temp.push_back(mat[top][j]);
            top++;
            for(int i = top;i <= down;i++) temp.push_back(mat[i][right]);
            right--;
            if(top <= down){
                for(int j = right;j >= left;j--) temp.push_back(mat[down][j]);
                down--;
            }
            if(left <= right){
                for(int i = down;i >= top;i--) temp.push_back(mat[i][left]);
                left++;
            }
        }
        return temp;
    }
};
