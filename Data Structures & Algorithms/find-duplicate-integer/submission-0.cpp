class Solution {
public:
    int findDuplicate(vector<int>& nums){
        unordered_set<int> st;
        for(int x : nums){
            if(!st.insert(x).second) return x;
        }
        return 0;
    }
};
