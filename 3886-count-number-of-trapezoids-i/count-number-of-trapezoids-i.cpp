class Solution {
public:
    int M = 1e9+7;
    int countTrapezoids(vector<vector<int>>& points) {
        long long total = 0;
        unordered_map<int,int>mpp;
        for(auto it : points){
            mpp[it[1]]++;
        }
        for(auto it : mpp){
            if(it.second < 2){
                continue;
            }
            total = (total + ((it.second)*1LL*(it.second-1)/2)%M)%M;
        }
        int ans = 0;
        for(auto it : mpp){
          if(it.second < 2){
            continue;
          }
          int temp = ((it.second)*1LL*(it.second-1)/2)%M;
          total = total - temp;
          ans = (ans + (temp*total)%M)%M;
        }
        return ans;
    }
};