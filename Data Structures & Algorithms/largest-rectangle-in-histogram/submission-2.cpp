class Solution {
public:
    int largestRectangleArea(vector<int>& H){
        stack<int> st;
        int maxArea = 0,n = H.size();
        for(int i = 0;i <= n;i++){
            while(!st.empty() && (i == n || H[st.top()] >= H[i])){
                int height = H[st.top()]; st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea,height * width);
            }
            st.push(i);
        }
        return maxArea;
    }
};
