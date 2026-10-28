/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& I){
        vector<int> st,end_;
        int n = I.size(),cnt = 0;
        for(int i = 0;i < n;i++){
            st.push_back(I[i].start);
            end_.push_back(I[i].end);
        }
        sort(st.begin(),st.end());
        sort(end_.begin(),end_.end());
        int i = 0,j = 0,maxi = 0;
        while(i < n && j < n){
            if(st[i] < end_[j]){ cnt++; i++; }
            else{ cnt--; j++; }
            maxi = max(maxi,cnt);
        }
        return maxi;
    }
};
