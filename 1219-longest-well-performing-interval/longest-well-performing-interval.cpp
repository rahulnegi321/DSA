class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int ans = 0;
        int n = hours.size();
        for(int i = 0;i<hours.size();i++){
            int count = 0;
            for(int j = i;j<hours.size();j++){
              if(hours[j] > 8){
                count++;
              }
              else{
                count--;
              }

              if(count > 0){
                ans = max(ans,j-i+1);
            }
            }
        }
        return ans;
    }
};