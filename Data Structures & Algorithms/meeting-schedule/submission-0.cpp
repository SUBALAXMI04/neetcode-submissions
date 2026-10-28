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
    bool canAttendMeetings(vector<Interval>& I){
        if(I.size() <= 1) return true;
        sort(I.begin(),I.end(),[](const Interval& a,const Interval& b){
            return a.start < b.start;
        });
        int end_ = I[0].end,n = I.size();
        for(int i = 1;i < n;i++){
            if(end_ > I[i].start) return false;
            else end_ = I[i].end;
        }
        return true;
    }
};
