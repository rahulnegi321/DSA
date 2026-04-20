class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int first = colors[0];
        int second;
        int ans = 0;
        int n = colors.size();
        for(int i = n-1;i>=1;i--){
            second = colors[i];
            if(second != first){
              ans = i;
              break;
            }
        }
        first = colors[n-1];
        for(int i = 0;i<n-1;i++){
            second = colors[i];
            if(second != first){
                ans = max(ans,n-i-1);
                break;
            }
        }
        return ans;
    }
};