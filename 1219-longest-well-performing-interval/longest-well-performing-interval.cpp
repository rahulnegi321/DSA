class Solution {
public:
    int longestWPI(vector<int>& hours) {
        unordered_map<int,int>mpp;
        int n = hours.size();
        mpp[0] = -1;
        vector<int>temp;
        for(int i = 0;i<n;i++){
            if(hours[i] > 8){
                temp.push_back(1);
            }
            else{
                temp.push_back(-1);
            }
        }
        int sum = 0;
        int ans = 0;
        for(int i = 0;i<n;i++){
          sum += temp[i];
          if(sum > 0){
             ans = i+1;
          }
          else{
            if(mpp.count(sum-1)){
                ans = max(ans,i-mpp[sum-1]);
            }
          }
          if(mpp.count(sum)){
            continue;
          }
          mpp[sum] = i;
        }
        return ans;
    }
};