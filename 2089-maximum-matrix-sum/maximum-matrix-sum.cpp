class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int neg = 0;
        int mini = INT_MAX;
        bool zero = false;
        long long final = 0;
        for(int i =0;i<matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                if(matrix[i][j] < 0){
                    neg++;
                }
                else if(matrix[i][j] == 0){
                    zero = true;
                }
                mini = min(mini,abs(matrix[i][j]));
                final += abs(matrix[i][j]);
            }
        }
        if(zero){
            return final;
        }
        if(neg%2 ==0){
            return final;
        }
        else{
            return final-2*mini;
        }
        return 0;
    }
};