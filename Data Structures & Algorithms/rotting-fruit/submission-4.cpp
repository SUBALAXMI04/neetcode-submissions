class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid){
        int m = grid.size(),n = grid[0].size(),cnt = 0,time = -1;
        queue<pair<int,int>> Q;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 2) Q.push({i,j});
                else if(grid[i][j] == 1) cnt++;
            }
        }
        vector<pair<int,int>> D = {{0,-1},{-1,0},{0,1},{1,0}};
        if(Q.empty()){
            if(cnt == 0) return 0;
            return -1;
        }
        while(!Q.empty()){
            int len = Q.size();
            while(len--){
                auto [r,c] = Q.front(); Q.pop();
                for(auto [dr,dc] : D){
                    int R = r + dr,C = c + dc;
                    if(R >= 0 && C >= 0 && R < m && C < n && grid[R][C] == 1){
                        Q.push({R,C});
                        grid[R][C] = 3;
                        cnt--;
                    }
                }
            }
            time++;
        }
        return (cnt == 0) ? time : -1;
    }
};
