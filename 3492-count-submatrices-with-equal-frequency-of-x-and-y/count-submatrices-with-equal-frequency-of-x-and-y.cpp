class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        unordered_map<char,int>mpp;
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<pair<int,int>>temp;
        for(int i = 0;i<m;i++){
            mpp[grid[0][i]]++;
            if(grid[0][i] == 'X'){
                temp.push_back({1,0});
            }
            else if(grid[0][i] == 'Y'){
                temp.push_back({0,1});
            }
            else{
                temp.push_back({0,0});
            }
            if(mpp['X'] >= 1 && mpp['Y'] == mpp['X']){
                count++;
            }
        }

        for(int i = 1;i<n;i++){
            unordered_map<char,int>curr;
            for(int j = 0;j<m;j++){
               curr[grid[i][j]]++;
               int x = temp[j].first;
               int y = temp[j].second;
               curr['X'] += x;
               curr['Y'] += y;
               if(grid[i][j] == 'X'){
                 temp[j].first++;
               }
               else if(grid[i][j] == 'Y'){
                temp[j].second++;
               }
               if(curr['X'] >= 1 && curr['Y'] == curr['X']){
                count++;
            }
            }
        }
        return count;
    }
};