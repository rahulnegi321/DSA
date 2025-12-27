class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        long long temp1 = accumulate(gas.begin(),gas.end(),0);
        long long temp2 = accumulate(cost.begin(),cost.end(),0);
        if(temp2 > temp1){
            return -1;
        }
        int n = gas.size();
        if(n == 1){
            return 0;
        }
        int i = 0;
        int ans = 0;
        int remain = 0;
        while(i < n){
           if(remain < 0){
             remain = gas[i];
             ans = i;
           }
           else{
            remain += gas[i];
           }
           remain -= cost[i];
           i++;
        }
        return ans;
    }
};