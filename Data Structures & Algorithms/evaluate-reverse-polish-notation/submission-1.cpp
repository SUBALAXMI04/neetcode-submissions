class Solution {
public:
    int evalRPN(vector<string>& tokens){
        stack<int> st;
        for(auto c : tokens){
            if(c != "+" && c != "-" && c != "*" && c != "/") st.push(stoi(c));
            else{
                int y = st.top(); st.pop();
                int x = st.top(); st.pop();
                if(c == "+") st.push(x + y);
                else if(c == "-") st.push(x - y);
                else if(c == "/") st.push(x/y);
                else st.push(x * y);
            }
        }
        return st.top();
    }
};
