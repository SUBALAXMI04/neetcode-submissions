class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& B){
        bool row[9][9] = {0},col[9][9] = {0},board[9][9] = {0};
        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++){
                if(B[i][j] == '.') continue;
                int d = B[i][j] - '1';
                int b = (i/3)*3 + (j/3);
                if(row[i][d] || col[j][d] || board[b][d]) return false;
                row[i][d] = true;
                col[j][d] = true;
                board[b][d] = true;
            }
        }
        return true;
    }
};
