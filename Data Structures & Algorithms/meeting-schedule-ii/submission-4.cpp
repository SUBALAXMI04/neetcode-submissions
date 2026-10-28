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
        // APPROACH 1
        // vector<int> st,end_;
        // int n = I.size(),cnt = 0;
        // for(int i = 0;i < n;i++){
        //     st.push_back(I[i].start);
        //     end_.push_back(I[i].end);
        // }
        // sort(st.begin(),st.end());
        // sort(end_.begin(),end_.end());
        // int i = 0,j = 0,maxi = 0;
        // while(i < n && j < n){
        //     if(st[i] < end_[j]){ cnt++; i++; }
        //     else{ cnt--; j++; }
        //     maxi = max(maxi,cnt);
        // }
        // return maxi;



        // APPROACH 2
        // vector<pair<int,int>> temp;
        // for(auto& i : I){
        //     temp.push_back({i.start,1});
        //     temp.push_back({i.end,-1});
        // }
        // sort(temp.begin(),temp.end(),[](auto& a,auto& b){
        //     if(a.first == b.first) return a.second < b.second;
        //     return a.first < b.first;
        // });
        // int cnt = 0,maxi = 0;
        // for(auto& p : temp){
        //     cnt += p.second;
        //     maxi = max(maxi,cnt);
        // }
        // return maxi;


        // APPROACH 3
        // map<int,int> mp;
        // for(auto& i : I){
        //     mp[i.start]++;
        //     mp[i.end]--;
        // }
        // int cnt = 0,maxi = 0;
        // for(auto& p : mp){
        //     cnt += p.second;
        //     maxi = max(maxi,cnt);
        // }
        // return maxi;
        


        // APPROACH 4
        priority_queue<int,vector<int>,greater<int>> pq;
        sort(I.begin(),I.end(),[](const auto& a,const auto& b){
            return a.start < b.start; 
        });
        for(auto& i : I){
            if(!pq.empty() && pq.top() <= i.start) pq.pop();
            pq.push(i.end);
        }
        return pq.size();
    }
};
