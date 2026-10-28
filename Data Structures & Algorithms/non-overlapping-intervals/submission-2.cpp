class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& I){
        int n = I.size(),cnt = 0;
        sort(I.begin(),I.end(),[](const vector<int>& a,const vector<int>& b){
            return a[1] < b[1];
        });
        int end = I[0][1];
        for(int i = 1;i < n;i++){
            if(end <= I[i][0]) end = I[i][1];
            else cnt++;
        }
        return cnt;
    }
};
