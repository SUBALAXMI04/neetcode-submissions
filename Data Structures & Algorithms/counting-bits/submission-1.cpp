class Solution {
public:
    vector<int> countBits(int n){
        vector<int> O = {0};
        while(O.size() * 2 <= n){
            int len = O.size();
            for(int i = 0;i < len;i++)
                O.push_back(1 + O[i]);
        }
        int size = n - O.size();
        for(int i = 0;i <= size;i++)
            O.push_back(1 + O[i]);
        return O;
    }
};
