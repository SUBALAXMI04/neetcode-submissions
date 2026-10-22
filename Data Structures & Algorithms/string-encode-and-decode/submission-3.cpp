class Solution {
public:

    string encode(vector<string>& strs){
        if(strs.empty()) return "";
        string data;
        for(auto &s : strs) data += to_string(s.size()) + "#" + s;
        return data;
    }

    vector<string> decode(string s){
        vector<string> ans;
        int i = 0,n = s.size();
        while(i < n){
            int j = i;
            while(s[j] != '#') j++;
            int len = stoi(s.substr(i,j - i));
            j++;
            ans.push_back(s.substr(j,len));
            i = j + len;
        }
        return ans;
    }
};
