class Solution {
public:
    vector<pair<int,int>> D = {{0,-1},{-1,0},{0,1},{1,0}};
    void bfs(int row,int col,vector<vector<char>>& grid){
        int m = grid.size(),n = grid[0].size();
        grid[row][col] = '2';
        queue<pair<int,int>> Q;
        Q.push({row,col});
        while(!Q.empty()){
            auto [r,c] = Q.front(); Q.pop();
            for(auto [dr,dc] : D){
                int R = r + dr,C = c + dc;
                if(R >= 0 && C >= 0 && R < m && C < n && grid[R][C] == '1'){
                    Q.push({R,C});
                    grid[R][C] = '2';
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid){
        int m = grid.size(),n = grid[0].size(),cnt = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == '1'){
                    bfs(i,j,grid);
                    cnt++;
                }
            }
        }
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++)
                if(grid[i][j] == '2') grid[i][j] = '1';
        return cnt;
    }
};
