class Solution {
public:
    int largestRectangleArea(vector<int>& H){
        stack<int> st;
        int n = H.size(),ans = 0;
        vector<int> left(n,-1);
        for(int i = 0;i < n;i++){
            while(!st.empty() && H[st.top()] >= H[i]) st.pop();
            if(!st.empty()) left[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n - 1;i >= 0;i--){
            int right = n;
            while(!st.empty() && H[st.top()] >= H[i]) st.pop();
            if(!st.empty()) right = st.top();
            ans = max(ans,H[i] * (right - left[i] - 1));
            st.push(i);
        }
        return ans;
    }
};
