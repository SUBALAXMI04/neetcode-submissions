class Solution {
public:
    bool isValid(int row,int col,vector<string>& board){
        int n = board.size();
        for(int i = 0;i < row;i++)
            if(board[i][col] == 'Q') return false;
        for(int j = 0;j < col;j++)
            if(board[row][j] == 'Q') return false;
        for(int i = row - 1,j = col - 1;i >= 0 && j >= 0;i--,j--)
            if(board[i][j] == 'Q') return false;
        for(int i = row - 1,j = col + 1;i >= 0 && j < n;i--,j++)
            if(board[i][j] == 'Q') return false;
        return true;
    }
    void solve(int row,vector<string>& curr,vector<vector<string>>& ans){
        if(row == curr.size()){
            ans.push_back(curr);
            return;
        }
        int n = curr.size();
        for(int col = 0;col < n;col++){
            if(isValid(row,col,curr)){
                curr[row][col] = 'Q';
                solve(row + 1,curr,ans);
                curr[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n){
        vector<vector<string>> ans;
        vector<string> curr(n,string(n,'.'));
        solve(0,curr,ans);
        return ans;
    }
};
