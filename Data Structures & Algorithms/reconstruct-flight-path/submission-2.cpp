class Solution {
public:
    bool dfs1(string src,unordered_map<string,deque<string>>& adj,vector<string>& ans,int targetLen){
        if(ans.size() == targetLen) return true;
        if(adj.find(src) == adj.end()) return false;
        deque<string> temp = adj[src];
        for(int i = 0;i < temp.size();i++){
            string v = temp[i];
            adj[src].erase(adj[src].begin() + i);
            ans.push_back(v);
            if(dfs1(v,adj,ans,targetLen)) return true;
            ans.pop_back();
            adj[src].insert(adj[src].begin() + i,v);
        }
        return false;
    }
    void dfs2(string src,unordered_map<string,deque<string>>& adj,vector<string>& ans){
        while(!adj[src].empty()){
            string dst = adj[src].back();
            adj[src].pop_back();
            dfs2(dst,adj,ans);
        }
        ans.push_back(src);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets){
        // APPROACH 1
        // unordered_map<string,deque<string>> adj;
        // for(auto &e : tickets) adj[e[0]].push_back(e[1]);
        // for(auto [src,dest] : adj) sort(dest.begin(),dest.end());
        // vector<string> ans = {"JFK"};
        // dfs1("JFK",adj,ans,tickets.size() + 1);
        // return ans;


        // APPROACH 2
        unordered_map<string,deque<string>> adj;
        for(auto &e : tickets) adj[e[0]].push_back(e[1]);
        for(auto& [src,dest] : adj) sort(dest.rbegin(),dest.rend());
        vector<string> ans;
        dfs2("JFK",adj,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
