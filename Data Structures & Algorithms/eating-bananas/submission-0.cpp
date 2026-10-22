class Solution {
public:
    bool possible(int limit,int hour,vector<int>& piles){
        int H = 0;
        for(int p : piles){
            H += (p + limit - 1)/limit;
            if(H > hour) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles,int h){
        int st = 1,end = *max_element(piles.begin(),piles.end());
        while(st < end){
            int mid = st + (end - st)/2;
            if(possible(mid,h,piles)) end = mid;
            else st = mid + 1;
        }
        return end;
    }
};
