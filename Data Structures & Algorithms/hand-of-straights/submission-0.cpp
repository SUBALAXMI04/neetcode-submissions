class Solution {
public:
    bool isNStraightHand(vector<int>& hand,int size){
        if(hand.size() % size != 0) return false;
        unordered_map<int,int> mp;
        sort(hand.begin(),hand.end());
        for(int x : hand) mp[x]++;
        for(int x : hand){
            if(mp[x] > 0){
                for(int i = x;i < x + size;i++){
                    if(mp[i] > 0) mp[i]--;
                    else return false;
                }
            }
        }
        return true;
    }
};
