class Solution {
public:
    vector<pair<int,int>> D = {{-1,0},{0,-1},{0,1},{1,0}};
    void solve(vector<vector<char>>& B){
        int m = B.size(),n = B[0].size();
        queue<pair<int,int>> Q;
        for(int i = 0;i < m;i++){
            if(B[i][0] == 'O'){
                B[i][0] = 'Y';
                Q.push({i,0});
            }
            if(B[i][n - 1] == 'O'){
                B[i][n - 1] = 'Y';
                Q.push({i,n - 1});
            }
        }
        for(int j = 0;j < n;j++){
            if(B[0][j] == 'O'){
                B[0][j] = 'Y';
                Q.push({0,j});
            }
            if(B[m - 1][j] == 'O'){
                B[m - 1][j] = 'Y';
                Q.push({m - 1,j});
            }
        }
        while(!Q.empty()){
            auto [r,c] = Q.front(); Q.pop();
            for(auto [dr,dc] : D){
                int R = r + dr,C = c + dc;
                if(R >= 0 && C >= 0 && R < m && C < n && B[R][C] == 'O'){
                    B[R][C] = 'Y';
                    Q.push({R,C});
                }
            }
        }
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(B[i][j] == 'O') B[i][j] = 'X';
                else if(B[i][j] == 'Y') B[i][j] = 'O';
            }
        }
    }
};
