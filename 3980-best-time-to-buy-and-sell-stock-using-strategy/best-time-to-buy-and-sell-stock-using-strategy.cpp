class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long original = 0;
        for(int  i= 0;i<prices.size();i++){
            original = original +  prices[i]*1LL*strategy[i];
        }
        long long changed = original;
        long long final = 0;
        for (int i = 0; i < k; i++) {
            changed -= 1LL * strategy[i] * prices[i]; 
            if (i >= k/2) {
                changed += prices[i];              
            }
        }
        final = max(changed,original);
        for(int i = 1;i+k-1<prices.size();i++){
          changed = changed + prices[i-1]*strategy[i-1];
            int mid = i + k/2 - 1;
            changed -= prices[mid];
          changed = changed + prices[i+k-1];
          changed = changed - prices[i+k-1]*strategy[i+k-1];
          final = max(changed,final);
        }
        return final;
    }
};