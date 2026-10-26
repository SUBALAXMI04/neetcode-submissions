class Solution {
public:
    vector<pair<int,int>> D = {{0,-1},{-1,0},{0,1},{1,0}};
    int swimInWater(vector<vector<int>>& grid){
        int n = grid.size();
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        pq.push({grid[0][0],0,0});
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        dist[0][0] = grid[0][0];
        while(!pq.empty()){
            auto [time,r,c] = pq.top(); pq.pop();
            if(r == n - 1 && c == n - 1) return dist[r][c];
            if(time > dist[r][c]) continue;
            for(auto [dr,dc] : D){
                int R = r + dr,C = c + dc;
                if(R >= 0 && C >= 0 && R < n && C < n){
                    int newTime = max(time,grid[R][C]);
                    if(newTime < dist[R][C]){
                        dist[R][C] = newTime;
                        pq.push({newTime,R,C});
                    }
                }
            }
        }
        return -1;
    }
};
