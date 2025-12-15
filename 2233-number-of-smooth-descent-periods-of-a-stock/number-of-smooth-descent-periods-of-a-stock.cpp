class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans  = 0;
        long long count = 1;
        int i = 0;
        int n = prices.size();
        while(i < n){
            if(i+1 < n && prices[i+1] == prices[i]-1){
                count++;
                i++;
            }
            else{
               ans = ans + (count*(count+1))/2;
               count = 1;
               i++;
            }
        }
        return ans;
    }
};