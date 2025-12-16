class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long ans = 0;
        long long ans2 = 0;
       
        while(n > k){
            ans = ans + (n-k)*1LL*(k);
            n = n-k;
        }
        while(m > k){
            ans2 = ans2 + (m-k)*1LL*(k);
            m = m-k;
        }
        return ans + ans2;
    }
};