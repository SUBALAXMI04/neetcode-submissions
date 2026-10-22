class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap(){ }
    
    void set(string key,string value,int timestamp){
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key,int timestamp){
        if(!mp.count(key)) return "";
        auto &v = mp[key];
        auto it = upper_bound(v.begin(),v.end(),timestamp,[](int x,const pair<int,string> &p){
            return x < p.first;
        });
        if(it == v.begin()) return "";
        return prev(it)->second;
    }
};
