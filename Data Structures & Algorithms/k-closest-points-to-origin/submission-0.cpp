class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points,int k){
        vector<vector<int>> ans;
        vector<pair<long long,int>> dist;
        for(int i = 0;i < points.size();i++){
            int x = points[i][0],y = points[i][1];
            dist.push_back({x*x + y*y,i});
        }
        sort(dist.begin(),dist.end());
        for(int i = 0;i < k;i++) ans.push_back(points[dist[i].second]);
        return ans;
    }
};
