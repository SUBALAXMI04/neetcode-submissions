class KthLargest {
public:
    int K;
    priority_queue<int,vector<int>,greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int x : nums) pq.push(x);
        while(pq.size() > K) pq.pop();
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > K) pq.pop();
        return pq.top();
    }
};
