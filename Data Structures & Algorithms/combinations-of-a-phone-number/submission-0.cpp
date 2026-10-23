class Solution {
public:
    vector<string> phone = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void solve(int idx,string digits,string curr,vector<string>& ans){
        if(idx == digits.size()){
            ans.push_back(curr);
            return;
        }
        for(char c : phone[digits[idx] - '0']){
            curr.push_back(c);
            solve(idx + 1,digits,curr,ans);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits){
        vector<string> ans;
        if(digits.empty()) return ans;
        string curr = "";
        solve(0,digits,curr,ans);
        return ans;
    }
};
