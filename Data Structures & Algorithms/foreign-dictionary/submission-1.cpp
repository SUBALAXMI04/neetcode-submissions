class Solution {
public:
    unordered_map<char,unordered_set<char>> adj;
    unordered_map<char,bool> vis;
    string ans;
    bool dfs(char node){
        if(vis.find(node) != vis.end()) return vis[node];
        vis[node] = true;
        for(auto v : adj[node]){
            if(dfs(v)) return true;
        }
        vis[node] = false;
        ans += node;
        return false;
    }
    string foreignDictionary(vector<string>& words){
        adj.clear();
        vis.clear();
        ans.clear();
        for(auto word : words){
            for(char c : word) adj[c];
        }
        for(int i = 0;i < words.size() - 1;i++){
            string w1 = words[i],w2 = words[i + 1];
            int minLen = min(w1.size(),w2.size());
            if(w1.size() > w2.size() && w1.substr(0,minLen) == w2.substr(0,minLen)) return "";
            for(int j = 0;j < minLen;j++){
                if(w1[j] != w2[j]){
                    adj[w1[j]].insert(w2[j]);
                    break;
                }
            }
        }
        for(auto& [node,neigh] : adj){
            if(dfs(node)) return "";
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
