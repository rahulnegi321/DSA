class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long total = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        unordered_map<int,int>mpp;
        unordered_map<int,int>mpp2;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                total += grid[i][j];
                mpp[grid[i][j]]++;
            }
        }
        mpp2 = mpp;
        long long dum = total;
        if(n == 1){
            long long curr = 0;
            for(int j = 0;j<m-1;j++){
               curr += grid[0][j];
               total -= grid[0][j];
               if(curr == total){
                return true;
               }
               if(curr > total){
                long long diff = curr-total;
                if(diff > 1e5){
                    continue;
                }
                if(grid[0][j] == diff || grid[0][0] == diff){
                  return true;
                }
               }
               else{
                long long diff = total-curr;
                if(diff > 1e5){
                    continue;
                }
                if(grid[0][j+1] == diff || grid[0][m-1] == diff){
                    return true;
                }
               }
            }
            return false;
        }
        if(m == 1){
            long long curr = 0;
            for(int i = 0;i<n-1;i++){
               curr += grid[i][0];
               total -= grid[i][0];
               if(curr == total){
                return true;
               }
               if(curr > total){
                long long diff = curr-total;
                if(diff > 1e5){
                    continue;
                }
                if(grid[i][0] == diff || grid[0][0] == diff){
                    return true;
                }
               }
               else{
                long long diff = total-curr;
                if(diff > 1e5){
                    continue;
                }
                if(grid[i+1][0] == diff || grid[n-1][0] == diff){
                    return true;
                }
               }
            }
            return false;
        }

        unordered_map<int,int>hor;
        long long curr = 0;
        for(int i = 0;i<n-1;i++){
            for(int j = 0;j<m;j++){
                curr += grid[i][j];
                total -= grid[i][j];
                hor[grid[i][j]]++;
                mpp[grid[i][j]]--;
            }
            if(curr == total){
                    return true;
                }
                else if(curr > total){
                    long long temp = curr - total;
                    if(temp > 1e5){
                        continue;
                    }
                    if(i == 0){
                        if((grid[0][0] == (int)temp || grid[0][m-1] == (int)temp)){
                            return true;
                        }
                        else{
                            continue;
                        }
                    }
                    if(hor[(int)temp] != 0){
                        return true;
                    }
                }
                else{
                    long long temp = total - curr;
                    if(temp > 1e5){
                        continue;
                    }
    
                    if(n-i == 2){
                        if((grid[n-1][0] == (int)temp || grid[n-1][m-1] == (int)temp)){
                            return true;
                        }
                        else{
                            continue;
                        }
                    }
                    if(mpp[(int)temp] != 0){
                        return true;
                    }
                }
        }
        mpp = mpp2;
        total = dum;
        unordered_map<int,int>ver;
        curr = 0;
        for(int j = 0;j<m-1;j++){
            for(int i = 0;i<n;i++){
                curr += grid[i][j];
                total -= grid[i][j];
                ver[grid[i][j]]++;
                mpp[grid[i][j]]--;
            }
            if(curr == total){
                    return true;
                }
                if(curr > total){
                    long long temp = curr - total;
                    if(temp > 1e5){
                        continue;
                    }
                    if(j == 0){
                        if((grid[0][0] == (int)temp || grid[n-1][0] == (int)temp)){
                            return true;
                        }
                        else{
                            continue;
                        }
                    }
                    if(ver[(int)temp] != 0){
                        return true;
                    }
                } 
                else{
                    long long temp = total - curr;
                    if(temp > 1e5){
                        continue;
                    }
                    if(m-j == 2){
                        if((grid[0][m-1] == (int)temp || grid[n-1][m-1] == (int)temp)){
                            return true;
                        }
                        else{
                            continue;
                        }
                    }
                    if(mpp[(int)temp] != 0){
                        return true;
                    }
                }
        }
        return false;
    }
};