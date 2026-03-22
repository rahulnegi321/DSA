class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       int n = matrix.size();
       for(int i = 0;i<n;i++){
        for(int  j =i;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
       }
       for(int i = 0;i<n;i++){
         reverse(matrix[i].begin(),matrix[i].end());
       }
       return;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
       int n = mat.size();
       int temp = 3;
       if(mat == target){
        return true;
       }
       while(temp--){
         rotate(mat);
         if(mat == target){
            return true;
         }
       }
       return false;
    }
};