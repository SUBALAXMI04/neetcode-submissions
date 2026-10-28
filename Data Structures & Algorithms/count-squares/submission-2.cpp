class CountSquares {
public:
    unordered_map<int,unordered_map<int,int>> mp;
    CountSquares(){ }
    
    void add(vector<int> point){
        mp[point[0]][point[1]]++;
    }
    
    int count(vector<int> point){
        int cnt = 0,x0 = point[0],y0 = point[1];
        for(auto [xd,yCnt] : mp){
            int side = abs(xd - x0);
            if(side == 0) continue;
            int yd = y0 + side;
            if(yCnt.count(y0) && mp[x0].count(yd))
                cnt += yCnt[yd] * mp[x0][yd] * yCnt[y0];
            yd = y0 - side;
            if(yCnt.count(y0) && mp[x0].count(yd))
                cnt += yCnt[yd] * mp[x0][yd] * yCnt[y0];
        }
        return cnt;
    }
};
