class Solution {
public:
    bool check(vector<vector<int>>&matrix,int mid,int k){
        int count = 0;
        int c = matrix[0].size()-1;
        
        for(int i = 0;i<matrix.size();i++){
            while(c >= 0 && matrix[i][c] > mid){
                c--;
            }
            count = count + (c+1);
        }
      if(count >= k){
        return true;
      }
      return false;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
      int n = matrix.size();
      int m = matrix[0].size();
      int low = matrix[0][0];
      int high = matrix[n-1][m-1];
      int ans = -1;
      while(low <= high){
        int mid = low + (high-low)/2;
        if(check(matrix,mid,k)){
         ans = mid;
         high = mid-1;
        }
        else{
            low = mid+1;
        }
      }
      return ans;
    }
};