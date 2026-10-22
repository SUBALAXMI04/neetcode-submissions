class Solution {
public:
    bool hasDuplicate(vector<int>& nums){
        unordered_set<int> st;
        for(int x : nums){
            if(!st.insert(x).second) return true;
        }
        return false;
    }
};