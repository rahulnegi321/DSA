class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>temp(m,0);
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(matrix[i][j] == 0){
                    temp[j]= 0;
                }
                else{
                    temp[j]++;
                }
            }
            vector<int>curr = temp;
            sort(curr.begin(),curr.end());
            for(int k = 0;k<m;k++){
                ans = max(ans,curr[k]*(m-k));
            }
        }
        return ans;
    }
};