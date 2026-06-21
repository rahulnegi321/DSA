class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
      int n = costs.size();
      sort(costs.begin(),costs.end());
      int ans = 0;
      for(int i = 0;i<n;i++){
        if(coins >= costs[i]){
            ans += 1;
            coins -= costs[i];
        }
      }
      return ans;
    }
};