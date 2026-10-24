class Solution {
public:
    vector<pair<int,int>> D = {{0,-1},{-1,0},{0,1},{1,0}};
    int bfs(int row,int col,vector<vector<int>>& grid){
        int m = grid.size(),n = grid[0].size(),area = 0;
        grid[row][col] = 2;
        queue<pair<int,int>> Q;
        Q.push({row,col});
        while(!Q.empty()){
            auto [r,c] = Q.front(); Q.pop();
            area++;
            for(auto [dr,dc] : D){
                int R = r + dr,C = c + dc;
                if(R >= 0 && C >= 0 && R < m && C < n && grid[R][C] == 1){
                    grid[R][C] = 2;
                    Q.push({R,C});
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid){
        int m = grid.size(),n = grid[0].size(),maxi = 0;
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++)
                if(grid[i][j] == 1) maxi = max(maxi,bfs(i,j,grid));
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++)
                if(grid[i][j] == 2) grid[i][j] = 1;
        return maxi;
    }
};
