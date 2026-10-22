class Solution {
public:
    int findDuplicate(vector<int>& nums){
        for(int x : nums){
            int idx = abs(x) - 1;
            if(nums[idx] < 0) return abs(x);
            nums[idx] *= -1;
        }
        return 0;





        // int fast = 0,slow = 0;
        // while(true){
        //     slow = nums[slow];
        //     fast = nums[nums[fast]];
        //     if(fast == slow){
        //         fast = 0;
        //         while(slow != fast){
        //             slow = nums[slow];
        //             fast = nums[fast];
        //         }
        //         return slow;
        //     }
        // }
        // return 0;





        // unordered_set<int> st;
        // for(int x : nums){
        //     if(!st.insert(x).second) return x;
        // }
        // return 0;
    }
};
