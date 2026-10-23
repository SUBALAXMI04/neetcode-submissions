class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points,int k){
        vector<vector<int>> ans;
        priority_queue<pair<long long,int>> pq;
        for(int i = 0;i < points.size();i++){
            int x = points[i][0],y = points[i][1];
            pq.push({x*x + y*y,i});
            if(pq.size() > k) pq.pop();
        }
        while(!pq.empty()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};
