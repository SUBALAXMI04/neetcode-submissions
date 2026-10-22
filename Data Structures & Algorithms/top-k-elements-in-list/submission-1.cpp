class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums,int k){
        unordered_map<int,int> freq;
        for(int x : nums) freq[x]++;
        int n = nums.size();
        vector<vector<int>> bucket(n + 1);
        for(auto &p : freq) bucket[p.second].push_back(p.first);
        vector<int> ans;
        for(int f = n;f >= 1;f--){
            for(auto x : bucket[f]){
                ans.push_back(x);
                if(ans.size() == k) return ans;
            }
        }
        return ans;

        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        // for(auto &p : freq){
        //     pq.push({p.second,p.first});
        //     if(pq.size() > k) pq.pop();
        // }
        // vector<int> ans;
        // while(!pq.empty()){
        //     ans.push_back(pq.top().second);
        //     pq.pop();
        // }
        // return ans;
    }
};
