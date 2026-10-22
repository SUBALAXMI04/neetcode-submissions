class Solution {
public:
    int findDuplicate(vector<int>& nums){
        int fast = 0,slow = 0;
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(fast == slow){
                fast = 0;
                while(slow != fast){
                    slow = nums[slow];
                    fast = nums[fast];
                }
                return slow;
            }
        }
        return 0;
        // unordered_set<int> st;
        // for(int x : nums){
        //     if(!st.insert(x).second) return x;
        // }
        // return 0;
    }
};
