class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
       
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        int x= 0;
        int y = 0;
        vector<pair<int,int>>temp;
        for(int i = 0;i<m;i++){
            if(grid[0][i] == 'X'){
                x++;
            }
            else if(grid[0][i] == 'Y'){
                y++;
            }
            if(grid[0][i] == 'X'){
                temp.push_back({1,0});
            }
            else if(grid[0][i] == 'Y'){
                temp.push_back({0,1});
            }
            else{
                temp.push_back({0,0});
            }
            if(x >= 1 && x == y){
                count++;
            }
        }

        for(int i = 1;i<n;i++){
            int countx = 0;
            int county = 0;
            for(int j = 0;j<m;j++){
               if(grid[i][j] == 'X'){
                countx++;
               }
               else if(grid[i][j] == 'Y'){
                county++;
               }

               int x = temp[j].first;
               int y = temp[j].second;
               countx += x;
               county += y;
               if(grid[i][j] == 'X'){
                 temp[j].first++;
               }
               else if(grid[i][j] == 'Y'){
                temp[j].second++;
               }
               if(countx >= 1 && countx == county){
                count++;
            }
            }
        }
        return count;
    }
};