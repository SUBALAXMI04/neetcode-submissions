class Solution {
public:
    int canCompleteCircuit(vector<int>& gas,vector<int>& cost){
        // APPROACH 1
        // int n = gas.size(),tank = 0;
        // for(int i = 0;i < n;i++){
        //     tank = gas[i] - cost[i];
        //     if(tank < 0) continue;
        //     int j = (i + 1) % n;
        //     while(j != i){
        //         tank += gas[j] - cost[j];
        //         if(tank < 0) break;
        //         j = (j + 1) % n;
        //     }
        //     if(j == i) return i;
        // }
        // return -1;


        // APPROACH 2
        // int end = 0,start = gas.size() - 1,tank = (gas[start] - cost[start]);;
        // while(start > end){
        //     if(tank < 0){
        //         start--;
        //         tank += (gas[start] - cost[start]);
        //     } else{
        //         tank += (gas[end] - cost[end]);
        //         end++;
        //     }
        // }
        // return (tank >= 0) ? start : -1; 


        // APPROACH 3
        int sumG = accumulate(gas.begin(),gas.end(),0);
        int sumC = accumulate(cost.begin(),cost.end(),0);
        if(sumG < sumC) return -1;
        int n = gas.size(),total = 0,stIdx = 0;
        for(int i = 0;i < n;i++){
            total += (gas[i] - cost[i]);
            if(total < 0){
                total = 0;
                stIdx = i + 1;
            }
        }
        return stIdx;
    }
};
