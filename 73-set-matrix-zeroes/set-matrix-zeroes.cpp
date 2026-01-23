class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0;
        bool temp = false;
        for(int i = 0;i<n;i++){
           if(matrix[i][0] == 0){
            temp = true;
            break;
           }
        }
        bool temp2 = false;
        for(int j = 0;j<m;j++){
            if(matrix[0][j] == 0){
                temp2 = true;
                break;
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 1987321;
                    matrix[i][0] = 1987321;
                }
            }
        }
        for(int i = 1;i<n;i++){
            if(matrix[i][0] == 1987321){
                for(int j = 0;j<m;j++){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j = 1;j<m;j++){
           if(matrix[0][j] == 1987321){
             for(int i = 0;i<n;i++){
                matrix[i][j] = 0;
             }
           }
        }
        if(matrix[0][0] == 1987321){
            if(temp){
                for(int i = 0;i<n;i++){
                    matrix[i][0] = 0;
                }
            }
            if(temp2){
                for(int j = 0;j<m;j++){
                matrix[0][j] = 0;
            }
            }
        }
        return;
    }
};