class Solution {
public:
    // unordered_map<char,unordered_set<char>> adj;
    // unordered_map<char,bool> vis;
    // string ans;
    // bool dfs(char node){
    //     if(vis.find(node) != vis.end()) return vis[node];
    //     vis[node] = true;
    //     for(auto v : adj[node]){
    //         if(dfs(v)) return true;
    //     }
    //     vis[node] = false;
    //     ans += node;
    //     return false;
    // }
    string foreignDictionary(vector<string>& words){
        unordered_map<char,unordered_set<char>> adj;
        unordered_map<char,int> indegree;
        string ans;
        for(string word : words){
            for(char c : word){
                adj[c] = unordered_set<char>();
                indegree[c] = 0;
            }
        }
        for(int i = 0;i < words.size() - 1;i++){
            string w1 = words[i],w2 = words[i + 1];
            int minLen = min(w1.size(),w2.size());
            if(w1.size() > w2.size() && w1.substr(0,minLen) == w2.substr(0,minLen)) return "";
            for(int j = 0;j < minLen;j++){
                if(w1[j] != w2[j]){
                    if(!adj[w1[j]].count(w2[j])){
                        adj[w1[j]].insert(w2[j]);
                        indegree[w2[j]]++;
                    }
                    break;
                }
            }
        }
        queue<char> Q;
        for(auto [x,f] : indegree){
            if(f == 0) Q.push(x);
        }
        while(!Q.empty()){
            auto node = Q.front(); Q.pop();
            for(auto v : adj[node]){
                indegree[v]--;
                if(indegree[v] == 0) Q.push(v);
            }
            ans += node;
        }
        return (ans.size() == indegree.size()) ? ans : "";







        // adj.clear();
        // vis.clear();
        // ans.clear();
        // for(auto word : words){
        //     for(char c : word) adj[c];
        // }
        // for(int i = 0;i < words.size() - 1;i++){
        //     string w1 = words[i],w2 = words[i + 1];
        //     int minLen = min(w1.size(),w2.size());
        //     if(w1.size() > w2.size() && w1.substr(0,minLen) == w2.substr(0,minLen)) return "";
        //     for(int j = 0;j < minLen;j++){
        //         if(w1[j] != w2[j]){
        //             adj[w1[j]].insert(w2[j]);
        //             break;
        //         }
        //     }
        // }
        // for(auto& [node,neigh] : adj){
        //     if(dfs(node)) return "";
        // }
        // reverse(ans.begin(),ans.end());
        // return ans;
    }
};
