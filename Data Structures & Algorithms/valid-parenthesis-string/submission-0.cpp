class Solution {
public:
    bool checkValidString(string s){
        int mini = 0,maxi = 0;
        for(char c : s){
            if(c == '('){ mini++; maxi++; }
            else if(c == ')'){ mini--; maxi--; }
            else{ mini--; maxi++; }
            mini = max(0,mini);
            if(maxi < 0) return false;
        }
        return mini == 0;
    }
};
