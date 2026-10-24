class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid){
        int m = grid.size(),n = grid[0].size(),dist = 1;
        queue<pair<int,int>> Q;
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++)
                if(grid[i][j] == 0) Q.push({i,j});
        vector<pair<int,int>> D = {{0,-1},{-1,0},{0,1},{1,0}};
        while(!Q.empty()){
            int len = Q.size();
            while(len--){
                auto [r,c] = Q.front(); Q.pop();
                for(auto [dr,dc] : D){
                    int R = r + dr,C = c + dc;
                    if(R >= 0 && C >= 0 && R < m && C < n && grid[R][C] == INT_MAX){
                        Q.push({R,C});
                        grid[R][C] = dist;
                    }
                }
            }
            dist++;
        }
    }
};
