class Solution {
public:
    int ladderLength(string begin,string end,vector<string>& dict){
        if(begin == end) return 0;
        unordered_set<string> st(dict.begin(),dict.end());
        if(!st.count(end)) return 0;
        queue<string> Q;
        Q.push(begin);
        if(st.count(begin)) st.erase(begin);
        int dist = 1;
        while(!Q.empty()){
            int len = Q.size();
            while(len--){
                auto word = Q.front(); Q.pop();
                if(word == end) return dist;
                for(int i = 0;i < word.size();i++){
                    char original = word[i];
                    for(char c = 'a';c <= 'z';c++){
                        word[i] = c;
                        if(st.count(word)){
                            st.erase(word);
                            Q.push(word);
                        }
                    }
                    word[i] = original;
                }
            }
            dist++;
        }
        return 0;
    }
};
