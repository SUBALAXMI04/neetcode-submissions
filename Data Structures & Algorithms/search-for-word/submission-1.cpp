class Solution {
public:
    bool dfs(int r,int c,int idx,string word,vector<vector<char>>& B){
        int m = B.size(),n = B[0].size();
        if(idx == word.size()) return true;
        if(r < 0 || c < 0 || r >= m || c >= n || B[r][c] != word[idx]) return false;
        char original = B[r][c];
        B[r][c] = '#';
        bool ans = dfs(r - 1,c,idx + 1,word,B) || dfs(r,c - 1,idx + 1,word,B) ||
               dfs(r + 1,c,idx + 1,word,B) || dfs(r,c + 1,idx + 1,word,B);
        B[r][c] = original;
        return ans;
    }
    bool exist(vector<vector<char>>& B,string word){
        int m = B.size(),n = B[0].size();
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++)
                if(dfs(i,j,0,word,B)) return true;
        return false;
    }
};
